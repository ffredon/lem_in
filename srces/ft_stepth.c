/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stepth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:50:56 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 14:59:56 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

t_path		*ft_pathfirst(t_path *path, t_l *link, t_s *stru)
{
	t_p		*places;

	places = stru->places->first;
	while (ft_strcmp(link->str, places->name))
		places = places->next;
	path->places = places;
	path->length = 1;
	if (places->end)
		path->over = 1;
	return (path);
}

t_path		*ft_nextpath(t_path *path, t_l *link, t_s *stru)
{
	t_path	*next;
	t_p		*places;

	if ((next = (t_path*)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	places = stru->places->first;
	while (ft_strcmp(link->str, places->name))
		places = places->next;
	if (places->start == 1 || (ft_alrdyhere(stru, link, path->up)))
		return (path);
	next = ft_initpath(next);
	next->places = places;
	next->length = path->length;
	next->first = path->first;
	next->up = path->up;
	path->next = next;
	if (places->end)
		next->over = 1;
	return (next);
}

t_path		*ft_firstpath(t_s *stru, t_path *path, t_p *places)
{
	t_l		*link;

	link = places->link;
	if (!link->str)
		path->over = 2;
	while (link->str)
	{
		while (path->next)
			path = path->next;
		if (!path->places->name)
			path = ft_pathfirst(path, link, stru);
		else
			path = ft_nextpath(path, link, stru);
		path->length = 1;
		if (path->over == 1)
			ft_algo(stru, path);
		if (link->next)
			link = link->next;
		else
			break ;
	}
	return (path);
}

int			ft_done(t_s *stru)
{
	t_path	*path;

	path = stru->path;
	if (!path)
		return (2);
	while (1)
	{
		if (path->over != 1)
			return (0);
		if (path->next)
			path = path->next;
		else
			return (1);
	}
	return (1);
}

t_s			*ft_stepth(t_s *stru)
{
	t_p		*places;
	t_path	*path;
	t_path	*path2;

	places = stru->places;
	while (!places->start)
		places = places->next;
	path = stru->path;
	path = ft_firstpath(stru, path, places);
	path2 = path;
	stru = ft_instepth(stru, path, path2);
	path = stru->path;
	while (1)
	{
		path2 = path;
		while (path->path)
			path = path->path;
		if (path2->next)
			path2 = path2->next;
		else
			break ;
		path = path2;
	}
	return (stru);
}
