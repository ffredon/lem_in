/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:58:42 by fredon            #+#    #+#             */
/*   Updated: 2016/01/19 14:08:35 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

long long			ft_getsigned(va_list *ap, t_list *lst)
{
	if (lst->hh)
		return ((long long)(signed char)(va_arg(*ap, int)));
	else if (lst->h)
		return ((long long)(short)(va_arg(*ap, int)));
	else if (lst->ll)
		return ((va_arg(*ap, long long)));
	else if (lst->l)
		return ((long long)(va_arg(*ap, long)));
	else if (lst->j)
		return ((long long)(va_arg(*ap, intmax_t)));
	else if (lst->t)
		return ((long long)(va_arg(*ap, ptrdiff_t)));
	else if (lst->z)
		return ((long long)(va_arg(*ap, long)));
	else
		return ((long long)(va_arg(*ap, int)));
}

unsigned long long	ft_getunsigned(va_list *ap, t_list *lst)
{
	if (lst->ll)
		return ((unsigned long long)(va_arg(*ap, unsigned long long)));
	else if (lst->j)
		return ((unsigned long long)(va_arg(*ap, uintmax_t)));
	else if (lst->l)
		return ((unsigned long long)(va_arg(*ap, unsigned long)));
	else if (lst->z)
		return ((unsigned long long)(va_arg(*ap, size_t)));
	else if (lst->t)
		return ((unsigned long long)(va_arg(*ap, ptrdiff_t)));
	else if (lst->hh)
		return ((unsigned long long)(unsigned char)(va_arg(*ap, int)));
	else if (lst->h)
		return ((unsigned long long)(unsigned short)(va_arg(*ap, int)));
	else
		return ((unsigned long long)(va_arg(*ap, unsigned int)));
}

long double			ft_getfloat(va_list *ap, t_list *lst)
{
	if (lst->lll)
		return (va_arg(*ap, long double));
	else if (lst->l)
		return ((long double)(va_arg(*ap, double)));
	else
		return ((long double)(va_arg(*ap, double)));
}
