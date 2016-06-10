/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:05:55 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 16:00:32 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

int			ft_countwords(char *line)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] != ' ')
			i++;
		if (line[i])
			i++;
		nb++;
	}
	return (nb);
}

int			ft_wordsize(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	return (i);
}

char		*ft_getword(char *line)
{
	int		i;
	char	*word;
	int		j;

	j = 0;
	i = ft_wordsize(line);
	if ((word = (char*)malloc(sizeof(*word) * (i + 1))) == NULL)
		return (NULL);
	while (j < i)
	{
		word[j] = line[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}
