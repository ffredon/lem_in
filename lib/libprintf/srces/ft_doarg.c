/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:19:48 by fredon            #+#    #+#             */
/*   Updated: 2016/01/21 10:30:36 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

int			ft_find(char *s, int i, t_list *lst)
{
	int		j;
	char	c;

	j = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		c = s[i];
		lst->opt++;
		j = j * 10;
		while (c > '0')
		{
			c--;
			j++;
		}
		i++;
	}
	return (j);
}

t_list		*ft_fieldarg(char *s, int i, va_list *ap, t_list *lst)
{
	lst->opt++;
	lst->field = va_arg(*ap, int);
	if (lst->field < 0)
	{
		lst->flag4 = 1;
		lst->field = -lst->field;
	}
	return (ft_path(s, i, ap, lst));
}
