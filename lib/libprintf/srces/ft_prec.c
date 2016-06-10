/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:50:55 by fredon            #+#    #+#             */
/*   Updated: 2016/01/21 09:41:07 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static int		ft_movve(t_list *lst)
{
	int		j;
	int		k;

	k = lst->prec;
	j = 0;
	while (k)
	{
		j++;
		k = k / 10;
	}
	if (lst->precp == 1 && j == 0)
		j = 1;
	return (j);
}

static t_list	*ft_wild(int i, t_list *lst)
{
	lst->prec = i;
	if (lst->prec < 0)
	{
		lst->prece = 0;
		lst->precp = 0;
		lst->prec = 0;
	}
	return (lst);
}

t_list			*ft_prec(char *s, int i, va_list *ap, t_list *lst)
{
	lst->opt++;
	lst->prece = 1;
	lst->precp = 0;
	lst->prec = 0;
	if (s[i] >= '0' && s[i] <= '9')
	{
		lst->precp = 1;
		lst->prec = ft_find(s, i, lst);
		i = i + ft_movve(lst);
	}
	else if (s[i] == '*')
	{
		lst->precp = 1;
		lst = ft_wild(va_arg(*ap, int), lst);
		i++;
		lst->opt++;
	}
	if (s[i] == 'h' || s[i] == 'l' || s[i] == 'j' || s[i] == 't' ||
			s[i] == 'z' || s[i] == 'L')
		return (ft_modif(s, i, ap, lst));
	return (ft_path(s, i - 1, ap, lst));
}
