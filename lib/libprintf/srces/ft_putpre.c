/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:16:31 by fredon            #+#    #+#             */
/*   Updated: 2016/01/09 14:39:32 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

void	ft_putprenb(char *s, t_list *lst)
{
	int		i;
	char	c;

	c = '0';
	i = 0;
	while (s[i])
		i++;
	while (i < lst->prec)
	{
		ft_putchar(1, &c, 1);
		i++;
	}
}

void	ft_putprenbonus(char *s, t_list *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '.')
		i++;
	while (s[i])
	{
		i++;
		j++;
	}
	while (j < lst->prec)
	{
		lst->trail++;
		j++;
	}
}

void	ft_putpreg(char *s, t_list *lst)
{
}

void	ft_putpres(char *s, t_list *lst)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (i > lst->prec)
	{
		s[i] = '\0';
		i--;
	}
}
