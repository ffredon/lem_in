/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 10:18:14 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 14:59:27 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

int			ft_sum(int *tab)
{
	int		sum;
	int		i;

	i = 0;
	sum = 0;
	while (tab[i])
	{
		sum = sum + tab[i];
		i++;
	}
	return (sum);
}

void		ft_destroy(t_path *next, t_path *path)
{
	if (next->next)
		path->next = next->next;
	else
		path->next = NULL;
	ft_suppress(next);
}

int			ft_up(t_p *places, t_path *path, t_l *link, t_s *stru)
{
	t_path	*up;

	up = path->up;
	while (1)
	{
		if (up && up->places->end == 1)
			return (0);
		if ((up && (!ft_strcmp(up->places->name, link->str))) ||
			places->start == 1 || (ft_alrdyhere(stru, link, up)))
			return (1);
		if (up == up->up || up == path->first)
			break ;
		up = up->up;
	}
	return (0);
}

t_path		*ft_pathinorm(t_path *path, t_l *link, t_s *stru)
{
	while (link->next)
	{
		link = link->next;
		if (path->over == 1)
			return (path);
		if (ft_isfirst(ft_nextpath(path, link, stru)))
			path = ft_nextpath(path, link, stru);
	}
	return (path);
}

t_s			*ft_linknorm(t_s *stru, t_l *link, t_p *places)
{
	while (1)
	{
		link = places->link;
		while (1)
		{
			while (link->str)
			{
				if (link->next)
					link = link->next;
				else
					break ;
			}
			if (link->next)
				link = link->next;
			else
				break ;
		}
		if (places->next)
			places = places->next;
		else
			break ;
	}
	return (stru);
}
