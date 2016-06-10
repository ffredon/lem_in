/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:16:14 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 15:09:02 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

void		ft_suppress(t_path *path)
{
	path->places = NULL;
	path->path = NULL;
	path->next = NULL;
	path->first = NULL;
	path->up = NULL;
	free(path);
}

void		ft_suppress2(t_path *path)
{
	t_path		*next;

	next = path->next;
	path->next = NULL;
	if (next)
	{
		ft_suppress2(next);
		ft_suppress(next);
	}
}

t_path		*ft_findover(t_path *path, t_path *path2)
{
	t_path	*next;

	if (path == path2)
		return (path);
	if (!path->places->end && !path->path && path != path2 && path->next)
	{
		next = path->next;
		path->up->path = next;
		ft_suppress(path);
		return (ft_findover(next, path2));
	}
	if (!path->places->end && !path->path && !path->next && path != path2)
	{
		path->up->path = NULL;
		next = path->up;
		ft_suppress(path);
		return (ft_findover(next, path2));
	}
	if (path->path && path->path != path2)
		return (ft_findover(path->path, path2));
	path->over = 1;
	return (path);
}

t_path		*ft_pathi(t_s *stru, t_path *path)
{
	t_p		*places;
	t_l		*link;
	t_path	*path2;

	places = path->places;
	link = places->link;
	if (!link->str && (path->over = 2))
		return (path);
	while (link->str)
	{
		if (!path->path || path->path == path)
			path2 = ft_pathpath(path, stru, link);
		else
			break ;
		if (link->next && (!path->path || path->path == path))
			link = link->next;
		else
			break ;
	}
	if ((path2 == path && (path->over = 2)) || path->over == 2)
		return (path);
	path = path->path;
	path = ft_pathinorm(path, link, stru);
	return (path);
}

t_path		*ft_makepath(t_s *stru, t_path *path)
{
	t_path	*path2;

	path2 = path;
	if (!path->path && path->over != 1)
		path2 = ft_pathi(stru, path);
	else
	{
		if (path->path && ((path2) && path2->over != 1))
			path2 = ft_makepath(stru, path->path);
		if (path->next && ((path2) && path2->over != 1))
			path2 = ft_makepath(stru, path->next);
	}
	if (path2 && (ft_supuseless(path2)))
		path2 = NULL;
	if (path && path->over == 1)
		path2->over = 1;
	return (path2);
}
