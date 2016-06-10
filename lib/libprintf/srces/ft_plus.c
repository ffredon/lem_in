/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:40:46 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:28:48 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"
#include <stdio.h>

void	ft_minus(int i, char *p, t_list *lst)
{
	int		j;
	int		len;

	len = ft_strlen2(p);
	if (p)
	{
		if ((p[0] != '-') && (!lst->flag2) && ((lst->flag3 || lst->flag5)))
			len++;
	}
	j = i;
	while ((lst->flag4) && (j > len))
	{
		ft_putchar(' ');
		j--;
	}
}

void	ft_sign(char *p, t_list *lst)
{
	if (p[0] != '-')
	{
		if (lst->flag5 && lst->flag2)
			ft_putchar('+');
	}
}

void	ft_plus(char *p, t_list *lst)
{
	if ((p[0] != '-') && (lst->flag2 == 0 || lst->field <= ft_strlen2(p)))
	{
		if (lst->flag3)
			ft_putchar(' ');
		else if (lst->flag5 && lst->flag2 == 0)
			ft_putchar('+');
	}
}
