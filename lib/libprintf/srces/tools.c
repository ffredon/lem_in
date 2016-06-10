/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 04:22:47 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:23:31 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

int		ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putint(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str, t_list *lst)
{
	int				i;

	i = 0;
	if (str)
	{
		if (lst->cap)
			ft_capitalize(str);
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}
