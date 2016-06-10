/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 08:56:49 by fredon            #+#    #+#             */
/*   Updated: 2016/01/18 15:02:28 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static t_list		*ft_flag1(char *s, int i, va_list *ap, t_list *lst)
{
	lst->flag1 = 1;
	return (ft_path(s, i, ap, lst));
}

static t_list		*ft_flag2(char *s, int i, va_list *ap, t_list *lst)
{
	if (lst->flag4 == 0)
		lst->flag2 = 1;
	return (ft_path(s, i, ap, lst));
}

static t_list		*ft_flag3(char *s, int i, va_list *ap, t_list *lst)
{
	if (lst->flag5 == 0)
		lst->flag3 = 1;
	return (ft_path(s, i, ap, lst));
}

static t_list		*ft_flag4(char *s, int i, va_list *ap, t_list *lst)
{
	lst->flag2 = 0;
	lst->flag4 = 1;
	return (ft_path(s, i, ap, lst));
}

t_list				*ft_flag(char *s, int i, va_list *ap, t_list *lst)
{
	lst->opt++;
	if (s[i] == '#')
		return (ft_flag1(s, i, ap, lst));
	else if (s[i] == '0')
		return (ft_flag2(s, i, ap, lst));
	else if (s[i] == ' ')
		return (ft_flag3(s, i, ap, lst));
	else if (s[i] == '-')
		return (ft_flag4(s, i, ap, lst));
	else
	{
		lst->flag3 = 0;
		lst->flag5 = 1;
		return (ft_path(s, i, ap, lst));
	}
}
