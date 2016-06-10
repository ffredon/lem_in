/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:09:16 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 10:39:47 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

t_l			*ft_initlink(t_l *link)
{
	link->str = NULL;
	link->next = NULL;
	link->first = link;
	return (link);
}

t_p			*ft_initplaces(t_p *places)
{
	t_l		*link;

	if ((link = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	link = ft_initlink(link);
	places->name = NULL;
	places->first = places;
	places->start = 0;
	places->end = 0;
	places->next = NULL;
	places->link = link;
	return (places);
}

t_path		*ft_initpath(t_path *path)
{
	t_p		*places;

	if ((places = (t_p*)malloc(sizeof(t_p))) == NULL)
		return (NULL);
	places = ft_initplaces(places);
	path->places = places;
	path->path = NULL;
	path->next = NULL;
	path->over = 0;
	path->length = 0;
	path->first = path;
	path->up = path;
	return (path);
}

t_s			*ft_initstru(t_s *stru)
{
	char	*str;
	t_p		*places;
	t_path	*path;

	if ((places = (t_p*)malloc(sizeof(t_p))) == NULL)
		return (NULL);
	if ((path = (t_path*)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	path = ft_initpath(path);
	places = ft_initplaces(places);
	str = NULL;
	stru->str = str;
	stru->ants = 0;
	stru->start = 0;
	stru->end = 0;
	stru->step = 0;
	stru->places = places;
	stru->path = path;
	if (((stru->tab = (int**)malloc(sizeof(int*) * 2)) == NULL))
		return (NULL);
	stru->tab = ft_initint(stru->tab);
	stru->opt = ft_initopt(stru);
	return (stru);
}

void		ft_start(int fd)
{
	char	*line;
	t_s		*stru;

	if ((stru = (t_s*)malloc(sizeof(t_s))) == NULL)
		exit(1);
	stru = ft_initstru(stru);
	while (get_next_line(fd, &line) && ft_noerror(stru))
	{
		stru = ft_modifs(stru, line);
		if (stru->step != 3 && (stru->str = ft_strjoin(stru->str, line)))
			stru->str = ft_strjoin(stru->str, "\n");
		if (stru->step == 3)
		{
			ft_printf("%s\n", stru->str);
			ft_printit(stru);
			exit(1);
		}
	}
	if (stru->step == 2 && (stru = ft_modifs(stru, "lol")))
	{
		ft_printf("%s\n", stru->str);
		ft_printit(stru);
	}
	else
		write(2, "ERROR", 5);
}
