/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 08:52:05 by fredon            #+#    #+#             */
/*   Updated: 2016/01/21 10:40:18 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static void		ft_winus(int j, wchar_t chr, t_list *lst)
{
	while ((lst->flag4 == 1) && (j > (int)ft_wlength(chr)))
	{
		ft_putchar(' ');
		j = j - 1;
	}
}

static t_list	*ft_lc(va_list *ap, t_list *lst)
{
	wchar_t	chr;
	int		j;

	chr = va_arg(*ap, wint_t);
	j = (int)ft_wlength(chr);
	if (lst->field == 0)
		lst->field = 1;
	while (lst->field > j)
	{
		if ((lst->flag2) && (lst->flag4 == 0))
			ft_putchar('0');
		else if (!lst->flag4)
			ft_putchar(' ');
		j = j + 1;
	}
	ft_putwchar(chr);
	ft_winus(j, chr, lst);
	lst->len = lst->len + j;
	return (lst);
}

t_list			*ft_c(va_list *ap, char *s, int i, t_list *lst)
{
	unsigned char	c;
	int				j;

	lst->opt++;
	j = 1;
	if ((lst->l) || (s[i] == 'C'))
		return (ft_lc(ap, lst));
	c = va_arg(*ap, int);
	(!lst->field) ? lst->field = 1 : 0;
	while (lst->field > j)
	{
		if ((lst->flag2) && (!lst->flag4))
			ft_putchar('0');
		else if (!lst->flag4)
			ft_putchar(' ');
		j = j + 1;
	}
	ft_putchar((char)c);
	while ((lst->flag4) && (j > 1))
	{
		ft_putchar(' ');
		j = j - 1;
	}
	lst->len = lst->len + lst->field;
	return (lst);
}
