/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 03:53:49 by fredon            #+#    #+#             */
/*   Updated: 2016/01/14 14:55:28 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

int		ft_printhexam(va_list ap)
{
	char			*p;
	unsigned int	c;

	c = va_arg(ap, unsigned int);
	p = ft_htoam(c);
	return (ft_strlen(p));
}

int		ft_printchar(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}
