/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:53:45 by fredon            #+#    #+#             */
/*   Updated: 2016/01/19 14:09:13 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

t_list		*ft_modif(char *s, int i, va_list *ap, t_list *lst)
{
	if (lst->hh == 1 && lst->h == 1 && s[i] == 'h')
	{
		lst->h = 0;
		lst->hh = 0;
	}
	else if (lst->ll == 1 && lst->l == 1 && s[i] == 'l')
	{
		lst->l = 0;
		lst->ll = 0;
	}
	(s[i] == 'h' && lst->h) ? lst->hh = 1 : 0;
	(s[i] == 'h') ? lst->h = 1 : 0;
	(s[i] == 'l' && lst->l) ? lst->ll = 1 : 0;
	(s[i] == 'l') ? lst->l = 1 : 0;
	s[i] == 'j' ? lst->j = 1 : 0;
	s[i] == 't' ? lst->t = 1 : 0;
	s[i] == 'z' ? lst->z = 1 : 0;
	s[i] == 'L' ? lst->lll = 1 : 0;
	lst->opt++;
	return (ft_path(s, i, ap, lst));
}
