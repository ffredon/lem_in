/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:51:52 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:32:09 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static char		*ft_utoa(unsigned long long n)
{
	char				*p;
	int					size;
	unsigned long long	x;

	x = n;
	size = 0;
	while (x > 9)
	{
		x /= 10;
		size++;
	}
	p = (char*)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 10;
			p[size] = 48 + x;
			n = n / 10;
			size--;
		}
	}
	return (p);
}

t_list			*ft_u(va_list *ap, char *s, int i, t_list *lst)
{
	char	*p;
	int		j;

	lst->opt++;
	if (lst->prece)
		lst->flag2 = 0;
	if (s[i] == 'U')
		lst->l = 1;
	p = ft_utoa(ft_getunsigned(ap, lst));
	p = ft_spec(p, lst, ft_strlen2(p));
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
