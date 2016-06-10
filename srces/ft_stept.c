/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stept.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:38:37 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 15:41:50 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

static int	ft_ctwords(char *line)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] != '-')
			i++;
		if (line[i])
			i++;
		nb++;
	}
	return (nb);
}

static int	ft_wrdsize(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	return (i);
}

char		*ft_gtword(char *line)
{
	int		i;
	char	*word;
	int		j;

	j = 0;
	i = ft_wrdsize(line);
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

int			ft_istube(t_s *stru, char *line)
{
	char	*word;

	if (ft_ctwords(line) != 2)
		return (0);
	word = ft_gtword(line);
	if (ft_cmpname(stru, word))
		return (0);
	free(word);
	while (*line != '-')
		line++;
	line++;
	word = ft_gtword(line);
	if (ft_cmpname(stru, word))
		return (0);
	free(word);
	return (1);
}

t_s			*ft_stept(t_s *stru, char *line)
{
	stru->step = 2;
	if (stru->start != 2 || stru->end != 2)
	{
		write(2, "ERROR", 5);
		exit(1);
	}
	if (line && line[0] == '#' && (ft_strcmp(line, "##start")) &&
		(ft_strcmp(line, "##end")))
		return (stru);
	if (ft_istube(stru, line) && ft_nolink(stru, line))
		return (ft_makelink(stru, line));
	stru->step = 3;
	return (ft_stepth(stru));
}
