/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:49:12 by fredon            #+#    #+#             */
/*   Updated: 2016/01/21 10:31:41 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static int	ft_move(t_list *lst)
{
	int		j;
	int		k;

	k = lst->field;
	j = 0;
	while (k)
	{
		j++;
		k = k / 10;
	}
	return (j);
}

t_list		*ft_path(char *s, int i, va_list *ap, t_list *lst)
{
	i++;
	if (s[i] > '0' && s[i] <= '9')
	{
		lst->field = ft_find(s, i, lst);
		i = i + ft_move(lst);
	}
	if (s[i] == '#' || s[i] == '0' || s[i] == ' ' || s[i] == '-' ||
			s[i] == '+')
		return (ft_flag(s, i, ap, lst));
	else if (s[i] == '*')
		return (ft_fieldarg(s, i, ap, lst));
	if (s[i] == '.')
		return (ft_prec(s, i + 1, ap, lst));
	else if (s[i] == 'h' || s[i] == 'l' || s[i] == 'j' || s[i] == 't' ||
			s[i] == 'z' || s[i] == 'L')
		return (ft_modif(s, i, ap, lst));
	else
		return (ft_chooseprint(ap, s, i, lst));
}
