/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stepz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:24:37 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 09:43:20 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

static int	ft_ispos(char *line)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
		if ((i == 0 && line[i] == '+') || (line[i] >= '0' && line[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	ft_atoip(char *str)
{
	unsigned int	i;
	int				c;

	i = 0;
	c = 0;
	if (str[c] == '+')
		c++;
	while (str[c] <= '9' && str[c] >= '0')
	{
		i = i * 10;
		i = i + str[c] - 48;
		c++;
	}
	if (i > 2147483647 || i == 0)
	{
		write(2, "ERROR", 5);
		exit(1);
	}
	return ((int)i);
}

t_s			*ft_stepz(t_s *stru, char *line)
{
	if (line && line[0] == '#' && (ft_strcmp(line, "##start")) &&
		(ft_strcmp(line, "##end")))
		return (stru);
	else if (line && *line && ft_strlen(line) <= 11 && ft_ispos(line))
	{
		stru->ants = ft_atoip(line);
		stru->step = 1;
		stru->opt->ants = ft_antlength(stru);
		return (stru);
	}
	else
	{
		write(2, "ERROR", 5);
		exit(1);
	}
	return (stru);
}
