/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 08:40:15 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 14:59:58 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

void			ft_next(t_path *path)
{
	t_path	*path2;

	if (path->up->path != path)
	{
		path2 = path->up->path;
		while (path2->next != path)
			path2 = path2->next;
		path2->next = path->next;
	}
	else
		path->up->path = path->next;
}

int				ft_isfirst(t_path *path)
{
	t_path	*tmp;

	tmp = path;
	while (tmp != tmp->up)
		tmp = tmp->up;
	while (1)
	{
		if (!ft_strcmp(path->places->name, tmp->places->name) &&
			tmp->places->end != 1)
			return (1);
		if (tmp->next)
			tmp = tmp->next;
		else
			return (0);
	}
}

int				ft_supuseless(t_path *path)
{
	t_path	*tmp;

	if (path->over == 2 && (ft_isfirst(path)))
		return (1);
	else if (path->over == 2 && path->next)
	{
		ft_next(path);
		tmp = path->next;
		ft_suppress(path);
		ft_supuseless(tmp);
		return (1);
	}
	else if (path->over == 2)
	{
		path->up->path = NULL;
		path->up->over = 2;
		tmp = path->up;
		ft_suppress(path);
		ft_supuseless(tmp);
		return (1);
	}
	return (0);
}

t_path			*ft_pathpath(t_path *path, t_s *stru, t_l *link)
{
	t_path		*path2;
	t_p			*places;
	t_path		*up;

	places = stru->places->first;
	while (ft_strcmp(places->name, link->str))
		places = places->next;
	up = path->up;
	if (ft_up(places, path, link, stru))
		return (path);
	if ((path2 = (t_path*)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	path2 = ft_initpath(path2);
	path2->places = places;
	path2->first = path->first;
	path2->up = path;
	path2->length = path->length + 1;
	if (path2->places->end == 1)
		path->over = 1;
	path->path = path2;
	if (ft_isfirst(path2))
		return (path);
	return (path2);
}

t_path			*ft_inter(t_path *path, t_s *stru)
{
	t_path	*path2;
	t_path	*path3;

	if (!path->path || path->path == path)
		path2 = ft_pathi(stru, path);
	else if ((path3 = path->path))
		path2 = ft_makepath(stru, path3);
	else
	{
		path->over = 2;
		path2 = path;
	}
	return (path2);
}
