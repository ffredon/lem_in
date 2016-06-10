/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 10:17:13 by fredon            #+#    #+#             */
/*   Updated: 2016/01/12 18:21:41 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

void		ft_wreduce(wchar_t *wstr, int i, t_list *lst)
{
	while (lst->prec < i)
	{
		wstr[i] = '\0';
		i--;
	}
}

void		ft_reduce(char *str, int i, t_list *lst)
{
	while (lst->prec < i)
	{
		str[i] = '\0';
		i--;
	}
}
