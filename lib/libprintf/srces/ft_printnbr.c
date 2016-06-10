/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 03:56:36 by fredon            #+#    #+#             */
/*   Updated: 2016/01/18 13:34:56 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

int		ft_printnbr(va_list ap, t_list *lst)
{
	char			*p;
	int				i;

	p = ft_itoa(va_arg(ap, int));
	i = ft_strlen(p);
	if (i < lst->prec)
		p = ft_grow(p, i, lst);
	if (p[0] != '-' && (lst->flag3 || lst->flag5))
		i++;
	if (lst->field > i)
		ft_morefield(i, lst);
	ft_plus(p, lst);
	ft_putstr(p);
	while ((lst->flag4) && (i > ft_strlen(p)))
	{
		ft_putchar(' ');
		i--;
	}
	return (i);
}

int		ft_printunsigned(va_list ap, t_list *lst)
{
	char			*p;
	int				i;

	p = ft_utoa(va_arg(ap, unsigned int));
	i = ft_strlen(p);
	if (i < lst->prec)
		p = ft_grow(p, i, lst);
	if (lst->field > i)
		ft_morefield(i, lst);
	ft_putstr(p);
	while ((lst->flag4) && (i > ft_strlen(p)))
	{
		ft_putchar(' ');
		i--;
	}
	return (i);
}

int		ft_printoctal(va_list ap, t_list *lst)
{
	char			*p;
	int				i;

	p = ft_otoa(va_arg(ap, unsigned int));
	if (lst->flag1 && lst->prec < ft_strlen(p))
		lst->prec = ft_strlen(p) + 1;
	i = ft_strlen(p);
	if (i < lst->prec)
		p = ft_grow(p, i, lst);
	if (lst->field > i)
		ft_morefield(i, lst);
	ft_putstr(p);
	while ((lst->flag4) && (i > ft_strlen(p)))
	{
		ft_putchar(' ');
		i--;
	}
	return (i);
}

int		ft_printhexa(va_list ap)
{
	char			*p;
	unsigned int	c;

	c = va_arg(ap, unsigned int);
	p = ft_htoa(c);
	ft_putstr(p);
	return (ft_strlen(p));
}

int		ft_printvoid(va_list ap)
{
	char			*p;
	unsigned long	c;

	ft_putstr("0x");
	c = va_arg(ap, unsigned long);
	p = ft_htoa(c);
	ft_putstr(p);
	return (ft_strlen(p) + 2);
}
