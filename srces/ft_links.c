/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:20:29 by fredon            #+#    #+#             */
/*   Updated: 2016/02/27 16:21:09 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

t_l			*ft_firstlink(t_l *link, char *word)
{
	link->str = word;
	return (link);
}

t_l			*ft_getlink(t_l *link, t_l *next, char *word)
{
	next = ft_initlink(next);
	next->first = link->first;
	next->str = word;
	link->next = next;
	return (link);
}

t_l			*ft_linktwo(t_l *link, char *line)
{
	t_l		*next;

	while (link->next)
		link = link->next;
	if (link == link->first && !link->str)
		link = ft_firstlink(link, ft_gtword(line));
	else
	{
		if ((next = (t_l*)malloc(sizeof(t_l))) == NULL)
			return (NULL);
		link = ft_getlink(link, next, ft_gtword(line));
	}
	return (link->first);
}

t_l			*ft_linkone(t_l *link, char *line)
{
	t_l		*next;

	while (link->next)
		link = link->next;
	if (link == link->first && !link->str)
		link = ft_firstlink(link, ft_gtscdword(line));
	else
	{
		if ((next = (t_l*)malloc(sizeof(t_l))) == NULL)
			return (NULL);
		link = ft_getlink(link, next, ft_gtscdword(line));
	}
	return (link->first);
}
