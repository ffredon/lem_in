/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:45:35 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:27:36 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static char		*ft_per(void)
{
	char	*p;

	p = (char*)malloc(sizeof(*p) * 2);
	p[0] = '%';
	p[1] = '\0';
	return (p);
}

t_list			*ft_percent(char *s, int i, t_list *lst)
{
	char	*p;
	int		j;

	if (s[i] != '%')
	{
		lst->len = -1;
		return (lst);
	}
	lst->opt++;
	p = ft_per();
	j = ft_strlen2(p);
	if (lst->field > j)
		j = ft_morefield(j, lst, p);
	ft_putstr(p, lst);
	ft_minus(j, p, lst);
	free(p);
	lst->len = lst->len + j;
	return (lst);
}
