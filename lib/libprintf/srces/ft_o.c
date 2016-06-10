/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:45:27 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:33:17 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static char		*ft_otoa(unsigned long long n)
{
	char				*p;
	int					size;
	unsigned long long	x;

	x = n;
	size = 0;
	while (x > 7)
	{
		x = x / 8;
		size++;
	}
	p = (char*)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			p[size] = 48 + x;
			n = n / 8;
			size--;
		}
	}
	return (p);
}

t_list			*ft_o(va_list *ap, char *s, int i, t_list *lst)
{
	char	*p;
	int		j;

	lst->opt++;
	lst->flag3 = 0;
	lst->flag5 = 0;
	if (lst->prece)
		lst->flag2 = 0;
	if (s[i] == 'O')
		lst->l = 1;
	p = ft_otoa(ft_getunsigned(ap, lst));
	p = ft_spec(p, lst, ft_strlen2(p));
	if (lst->flag1 && lst->prec <= ft_strlen2(p) && p[0] != '0')
		lst->prec = ft_strlen2(p) + 1;
	j = ft_strlen2(p);
	if (j < lst->prec)
		p = ft_grow(p, j, lst);
	j = ft_strlen2(p);
	if (lst->field > j)
		j = ft_morefield(j, lst, p);
	ft_putstr(p, lst);
	ft_minus(j, p, lst);
	free(p);
	lst->len = lst->len + j;
	return (lst);
}
