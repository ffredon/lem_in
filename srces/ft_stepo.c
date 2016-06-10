/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stepo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:29:42 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 16:00:34 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

static long int	ft_int(char *word)
{
	long int	i;
	int			c;
	int			sign;

	i = 0;
	c = 0;
	sign = 1;
	if (word[c] == '-')
	{
		sign = -1;
		c++;
	}
	else if (word[c] == '+')
		c++;
	while (word[c] <= '9' && word[c] >= '0')
	{
		i = i * 10;
		i = i + word[c] - 48;
		c++;
	}
	i = sign * i;
	return (i);
}

static int		ft_notint(char *word)
{
	if (ft_strlen(word) > 11)
		return (1);
	else if (ft_int(word) > 2147483647 || ft_int(word) < -2147483648)
		return (1);
	return (0);
}

static int		ft_isnumber(char *word)
{
	int		i;

	i = 0;
	if (!word[0])
		return (0);
	while (word[i])
	{
		if (i == 0 && (word[i] == '-' || word[i] == '+'))
			i++;
		if (word[i] >= '0' && word[i] <= '9')
			i++;
		else
			return (0);
	}
	if (ft_notint(word))
		return (0);
	return (1);
}

static int		ft_isplace(char *line)
{
	char	*word;

	if (ft_countwords(line) != 3)
		return (0);
	if (line[0] == 'L')
		return (0);
	while (*line != ' ')
		line++;
	line++;
	word = ft_getword(line);
	if (!ft_isnumber(word))
		return (0);
	free(word);
	while (*line != ' ')
		line++;
	line++;
	word = ft_getword(line);
	if (!ft_isnumber(line))
		return (0);
	free(word);
	return (1);
}

t_s				*ft_stepo(t_s *stru, char *line)
{
	if (line && line[0] == '#' && (ft_strcmp(line, "##start")) &&
		(ft_strcmp(line, "##end")))
		return (stru);
	else if (line && stru->start && stru->end &&
			ft_istube(stru, line) && ((stru->step = 1)))
		return (ft_stept(stru, line));
	else if (line && !ft_strcmp(line, "##start") &&
			stru->start == 0 && stru->end != 1)
	{
		stru->start = 1;
		return (stru);
	}
	else if (line && !ft_strcmp(line, "##end") &&
			stru->end == 0 && stru->start != 1)
	{
		stru->end = 1;
		return (stru);
	}
	else if (line && ft_isplace(line))
		return (ft_takeplace(stru, line));
	else
	{
		write(2, "ERROR", 5);
		exit(1);
	}
}
