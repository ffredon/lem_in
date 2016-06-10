/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suppathfst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:40:05 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 13:15:43 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

int			ft_comp(t_path *path, t_l *link, t_path *up)
{
	while (up != up->up)
	{
		if ((!ft_strcmp(path->places->name, link->str) &&
			path->places->end != 1) ||
			((!ft_strcmp(up->places->name, link->str) &&
			up->places->end != 1)))
			return (1);
		up = up->up;
		path = up;
	}
	return (0);
}

int			ft_alrdyhere(t_s *stru, t_l *link, t_path *up)
{
	t_path	*path;
	t_path	*tmp;

	path = stru->path;
	while (path)
	{
		if (path->over == 1)
		{
			tmp = path;
			while (1)
			{
				if (ft_comp(tmp, link, up))
					return (1);
				if (tmp->path)
					tmp = tmp->path;
				else
					break ;
			}
		}
		if (path->next)
			path = path->next;
		else
			break ;
	}
	return (0);
}

void		ft_replacefirst(t_path *path)
{
	t_path	*next;

	if (!path)
		return ;
	path->up = path;
	if (path->next)
		next = path->next;
	path->up = path;
	while (path->next)
	{
		next->up = next;
		if (next->next)
			next = next->next;
		else
			break ;
	}
}

t_path		*ft_suppath(t_s *stru, t_path *path)
{
	t_path	*tmp;

	if (path->up == path)
		return (ft_suppathfst(stru, path));
	tmp = path->up;
	while (tmp->next != path)
		tmp = tmp->next;
	tmp->next = path->next;
	ft_suppress(path);
	return (tmp->next);
}

t_path		*ft_suppathfst(t_s *stru, t_path *path)
{
	t_path	*tmp;

	if (stru->path != path)
	{
		tmp = stru->path;
		while (tmp->next != path)
			tmp = tmp->next;
		tmp->next = path->next;
		tmp = path->next;
		ft_suppress(path);
		path = tmp;
	}
	else
	{
		stru->path = path->next;
		ft_replacefirst(path->next);
		tmp = path->next;
		ft_suppress(path);
		path = tmp;
	}
	return (path);
}
