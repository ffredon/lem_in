/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 13:26:37 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:32:22 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static int		hexvalue(int x)
{
	if (0 <= x && x <= 9)
		return (48 + x);
	else if (10 <= x && x <= 15)
	{
		x = x - 10;
		return ('a' + x);
	}
	return (0);
}

static char		*ft_add(char *p, t_list *lst)
{
	int		len;

	len = ft_strlen2(p);
	if (lst->flag1 && (p[0] != '0' || len > 1))
	{
		p[0] = '0';
		p[1] = 'x';
	}
	return (p);
}

static int		test(t_list *lst)
{
	int		size;

	size = 0;
	if (lst->flag1)
		size = 2;
	return (size);
}

static char		*ft_htoa(unsigned long long n, t_list *lst)
{
	char				*p;
	int					size;
	unsigned long long	x;

	x = n;
	size = test(lst);
	while (x >= 16)
	{
		x = x / 16;
		size++;
	}
	p = (char*)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0 && (n || (!lst->prece)))
		{
			x = n % 16;
			p[size] = hexvalue(x);
			n = n / 16;
			size--;
		}
		p = ft_add(p, lst);
	}
	return (p);
}

t_list			*ft_p(va_list *ap, t_list *lst)
{
	char	*p;
	int		j;

	lst->opt++;
	if (lst->prece)
		lst->flag2 = 0;
	lst->flag1 = 1;
	p = ft_htoa((unsigned long long)va_arg(*ap, unsigned long), lst);
	j = ft_strlen2(p);
	if (j < lst->prec)
		p = ft_grow(p, j, lst);
	j = ft_strlen2(p);
	if (lst->field > j)
		j = ft_morefield(j, lst, p);
	p = ft_specx(p, lst);
	ft_putstr(p, lst);
	ft_minus(j, p, lst);
	free(p);
	lst->len = lst->len + j;
	return (lst);
}
