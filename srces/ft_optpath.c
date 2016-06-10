/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:40:31 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 11:58:37 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

void		ft_optpath(t_s *stru)
{
	t_path	*path;
	t_path	*tmp;

	path = stru->path;
	while (1)
	{
		ft_printf("%s IS A PATH, FOLLOWED BY : ", path->places->name);
		tmp = path;
		while (tmp->path)
		{
			tmp = tmp->path;
			ft_printf("%s ", tmp->places->name);
		}
		ft_printf("\n");
		if (path->next)
			path = path->next;
		else
			break ;
	}
}

char		*ft_color(t_s *stru, char *str, t_p *places)
{
	char	*tmp;

	if (!stru->opt->color)
		return (str);
	else if (places->end == 1)
	{
		tmp = ft_strjoin("\033[1m\033[31m", str);
		tmp = ft_strjoin(tmp, "\033[0m");
		return (tmp);
	}
	else
	{
		tmp = ft_strjoin("\033[1m\033[32m", str);
		tmp = ft_strjoin(tmp, "\033[0m");
		return (tmp);
	}
}

char		*ft_colori(t_s *stru, char *str, t_p *places)
{
	char	*tmp;

	if (!stru->opt->color)
		return (str);
	else if (places->end == 1)
	{
		tmp = ft_strjoin("\033[1m\033[31m", str);
		tmp = ft_strjoin(tmp, "\033[0m");
		return (tmp);
	}
	else
	{
		tmp = ft_strjoin("\033[1m\033[33m", str);
		tmp = ft_strjoin(tmp, "\033[0m");
		return (tmp);
	}
}
