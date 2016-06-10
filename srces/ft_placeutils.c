/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:43:37 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 15:57:47 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

int		ft_atoidel(char *str)
{
	int		i;
	int		c;
	int		sign;

	i = 0;
	c = 0;
	sign = 1;
	if (str[c] == '-')
	{
		sign = -1;
		c++;
	}
	else if (str[c] == '+')
		c++;
	while (str[c] <= '9' && str[c] >= '0')
	{
		i = i * 10;
		i = i + str[c] - 48;
		c++;
	}
	i = sign * i;
	free(str);
	return (i);
}

char	*ft_gettdword(char *line)
{
	while (*line && *line != ' ')
		line++;
	if (*line)
		line++;
	while (*line && *line != ' ')
		line++;
	if (*line)
		line++;
	return (ft_getword(line));
}

char	*ft_getscdword(char *line)
{
	while (*line && *line != ' ')
		line++;
	line++;
	return (ft_getword(line));
}
