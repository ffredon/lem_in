/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 03:43:48 by fredon            #+#    #+#             */
/*   Updated: 2016/01/18 16:55:06 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

t_list		*ft_init(t_list *lst)
{
	lst->flag1 = 0;
	lst->flag2 = 0;
	lst->flag3 = 0;
	lst->flag4 = 0;
	lst->flag5 = 0;
	lst->flag6 = 0;
	lst->field = 0;
	lst->prece = 0;
	lst->precp = 0;
	lst->prec = 0;
	lst->hh = 0;
	lst->h = 0;
	lst->l = 0;
	lst->ll = 0;
	lst->j = 0;
	lst->t = 0;
	lst->z = 0;
	lst->lll = 0;
	lst->trail = 0;
	lst->cap = 0;
	lst->opt = 0;
	return (lst);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	t_list	*lst;

	i = 0;
	va_start(ap, format);
	if ((lst = malloc(sizeof(*lst) * 50)) == NULL)
		return (-1);
	lst->len = 0;
	while (format[i] != '\0')
	{
		lst = ft_init(lst);
		if (format[i] == '%' && format[i + 1])
		{
			lst = ft_path((char*)format, i, &ap, lst);
			i = i + lst->opt;
		}
		else if (format[i] != '%')
			lst->len += ft_putchar(format[i]);
		i++;
	}
	i = lst->len;
	free(lst);
	va_end(ap);
	return (i);
}
