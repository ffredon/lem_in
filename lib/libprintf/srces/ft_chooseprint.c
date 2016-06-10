/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chooseprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:15:15 by fredon            #+#    #+#             */
/*   Updated: 2016/01/19 14:08:03 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

t_list		*ft_chooseprint(va_list *ap, char *s, int i, t_list *lst)
{
	if (s[i] == 'd' || s[i] == 'i' || s[i] == 'D')
		return (ft_d(ap, s, i, lst));
	else if (s[i] == '%')
		return (ft_percent(s, i, lst));
	else if (s[i] == 'x' || s[i] == 'X')
		return (ft_x(ap, s, i, lst));
	else if (s[i] == 's' || s[i] == 'S')
		return (ft_s(ap, s, i, lst));
	else if (s[i] == 'c' || s[i] == 'C')
		return (ft_c(ap, s, i, lst));
	else if (s[i] == 'o' || s[i] == 'O')
		return (ft_o(ap, s, i, lst));
	else if (s[i] == 'u' || s[i] == 'U')
		return (ft_u(ap, s, i, lst));
	else if (s[i] == 'p')
		return (ft_p(ap, lst));
	return (lst);
}
