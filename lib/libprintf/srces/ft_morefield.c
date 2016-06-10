/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_morefield.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 10:20:25 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:28:25 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

char	*ft_specx(char *p, t_list *lst)
{
	char	*str;
	int		len;

	if (p[0] == '0' && p[1] == 'x' && lst->field > ft_strlen2(p) && lst->flag2)
	{
		len = ft_strlen2(p) - 1;
		if ((str = (char*)malloc(sizeof(*str) * len)) == 0)
			return (NULL);
		len--;
		while (len + 2)
		{
			str[len] = p[len + 2];
			len--;
		}
		free(p);
		return (str);
	}
	return (p);
}

int		ft_morefield(int i, t_list *lst, char *p)
{
	if (p)
	{
		if (p[0] == '0' && p[1] == 'x' && lst->flag2)
		{
			ft_putchar('0');
			lst->cap ? ft_putchar('X') : ft_putchar('x');
		}
		if (p[0] == '-' && lst->flag2)
			ft_putchar('-');
		else if (p[0] != '-' && lst->flag2 && lst->flag3)
			ft_putchar(' ');
	}
	while (lst->field > i)
	{
		if (lst->flag2)
		{
			ft_putchar('0');
		}
		else if (!lst->flag4)
			ft_putchar(' ');
		i++;
	}
	return (i);
}
