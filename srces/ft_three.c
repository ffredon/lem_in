/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:28:37 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 15:40:47 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

int		ft_cmpname(t_s *stru, char *word)
{
	t_p		*places;

	places = stru->places->first;
	while (ft_strlen(word))
	{
		if (!ft_strcmp(places->name, word))
			return (0);
		if (places->next)
			places = places->next;
		else
			break ;
	}
	return (1);
}

int		ft_nolink(t_s *stru, char *line)
{
	t_l		*link;
	t_p		*places;
	char	*word;

	places = stru->places;
	word = ft_gtword(line);
	while (ft_strcmp(places->name, word))
		places = places->next;
	link = places->link;
	while (*line != '-')
		line++;
	line++;
	free(word);
	word = ft_gtword(line);
	while (link->str && ft_strcmp(link->str, word) && link->next)
		link = link->next;
	if (link->str && (!ft_strcmp(link->str, word) ||
		!ft_strcmp(word, places->name)))
	{
		free(word);
		return (0);
	}
	free(word);
	return (1);
}

char	*ft_gtscdword(char *line)
{
	while (*line != '-')
		line++;
	line++;
	return (ft_gtword(line));
}

t_s		*ft_makelink(t_s *stru, char *line)
{
	t_l		*link;
	t_p		*places;
	char	*word;

	places = stru->places;
	word = ft_gtword(line);
	while (ft_strcmp(places->name, word))
		places = places->next;
	link = places->link;
	link = ft_linkone(link, line);
	places = places->first;
	free(word);
	word = ft_gtscdword(line);
	while (ft_strcmp(places->name, word))
		places = places->next;
	link = places->link;
	link = ft_linktwo(link, line);
	places = stru->places;
	stru = ft_linknorm(stru, link, places);
	return (stru);
}
