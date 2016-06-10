/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takeplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:41:53 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 15:51:11 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

static t_p	*ft_newplace(t_s *stru, t_p *places, t_p *next, char *line)
{
	next = ft_initplaces(next);
	next->name = ft_getword(line);
	next->x = ft_atoidel(ft_getscdword(line));
	next->y = ft_atoidel(ft_gettdword(line));
	next->first = places->first;
	if (stru->start == 1)
		next->start = 1;
	if (stru->end == 1)
		next->end = 1;
	places->next = next;
	return (places);
}

static t_p	*ft_firstplace(t_s *stru, t_p *places, char *line)
{
	places->name = ft_getword(line);
	places->x = ft_atoidel(ft_getscdword(line));
	places->y = ft_atoidel(ft_gettdword(line));
	if (stru->start == 1)
		places->start = 1;
	if (stru->end == 1)
		places->end = 1;
	return (places);
}

int			ft_equalplace(t_p *places, char *line)
{
	char	*word;

	while (places)
	{
		word = ft_getword(line);
		if ((places->name && !ft_strcmp(places->name, word)) ||
			(places->x == ft_atoidel(ft_getscdword(line)) &&
			places->y == ft_atoidel(ft_gettdword(line))))
		{
			free(word);
			return (1);
		}
		free(word);
		if (places->next)
			places = places->next;
		else
			return (0);
	}
	return (0);
}

static t_p	*ft_makeplace(t_s *stru, t_p *places, char *line)
{
	t_p		*next;

	next = NULL;
	if (ft_equalplace(places, line))
	{
		write(2, "ERROR", 5);
		exit(1);
	}
	while (places->next)
		places = places->next;
	if (places == places->first && !places->name)
		places = ft_firstplace(stru, places, line);
	else
	{
		if ((next = (t_p*)malloc(sizeof(t_p))) == NULL)
			return (NULL);
		places = ft_newplace(stru, places, next, line);
	}
	ft_tiret(places->name);
	return (places->first);
}

t_s			*ft_takeplace(t_s *stru, char *line)
{
	stru->places = ft_makeplace(stru, stru->places, line);
	if (stru->start == 1)
		stru->start = 2;
	if (stru->end == 1)
		stru->end = 2;
	return (stru);
}
