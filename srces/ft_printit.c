/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:57:06 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 15:08:59 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

void	ft_turnit(t_path *path, int tmp, t_s *stru)
{
	int		tmp2;

	while (path)
	{
		if (path->over)
		{
			tmp = path->over;
			path->over = 0;
			while (path->path && tmp)
			{
				path = path->path;
				ft_printf("L%d-%-*s", tmp, stru->opt->length,
						ft_color(stru, path->places->name, path->places));
				if (stru->ants)
					ft_printf(" ");
				tmp2 = path->over;
				path->over = tmp;
				tmp = tmp2;
				tmp2 = 0;
			}
			return ;
		}
		else
			path = path->path;
	}
}

void	ft_turn(t_s *stru)
{
	int		tmp;
	t_path	*path;

	if (stru->opt->number)
		ft_printf("%d TURNS LEFT : ", stru->start);
	path = stru->path;
	while (path)
	{
		tmp = 0;
		ft_turnit(path, tmp, stru);
		if (path->next)
			path = path->next;
		else
			break ;
	}
}

void	ft_cleanit(t_s *stru)
{
	t_path	*path;
	t_path	*tmp;

	tmp = NULL;
	path = stru->path;
	while (path)
	{
		path->over = 0;
		if (path->path)
			tmp = path;
		while (tmp && tmp->path && !(tmp->path->over = 0))
			tmp = tmp->path;
		if (path->next)
			path = path->next;
		else
			break ;
	}
}

void	ft_makeenter(int x, t_path *path, t_s *stru)
{
	path->over = x;
	ft_printf("L%d-%-*s", x, stru->opt->length,
			ft_colori(stru, path->places->name, path->places));
	while (1)
	{
		if (path->next)
			path = path->next;
		else
			break ;
		if (path->length <= stru->start && x < stru->ants && (ft_printf(" ")))
			break ;
	}
}

void	ft_printit(t_s *stru)
{
	int		x;
	t_path	*path;

	x = 1;
	ft_cleanit(stru);
	stru = ft_getlength(stru);
	while (stru->start && stru->opt->silence == 0)
	{
		path = stru->path;
		ft_turn(stru);
		while (path)
		{
			if (path->length <= stru->start && x <= stru->ants)
			{
				ft_makeenter(x, path, stru);
				x++;
			}
			if (path->next)
				path = path->next;
			else
				break ;
		}
		stru->start--;
		ft_printf("\n");
	}
}
