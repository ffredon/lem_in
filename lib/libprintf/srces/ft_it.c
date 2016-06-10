/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_it.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:00:32 by fredon            #+#    #+#             */
/*   Updated: 2016/01/19 14:09:01 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static int	ft_nbrlen(unsigned long long n)
{
	int					i;
	unsigned long long	nb;

	i = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*test2(unsigned long long n)
{
	unsigned long long	val;
	int					len;
	char				*str;

	val = n;
	len = ft_nbrlen(n);
	str = (char*)malloc(sizeof(str) * (len + 1));
	if (str)
	{
		str[len] = '\0';
		while (len--)
		{
			str[len] = (n % 10) + 48;
			n = n / 10;
		}
	}
	return (str);
}

static int	test(t_list *lst)
{
	if (lst->ll || lst->j)
	{
		if (lst->z || lst->hh || lst->h || (lst->ll && lst->j))
			return (1);
	}
	else if (lst->l || lst->z)
	{
		if (lst->hh || lst->h || (lst->l && lst->z))
			return (1);
	}
	return (0);
}

char		*ft_it(va_list *ap, t_list *lst)
{
	int		i;

	i = test(lst);
	if (i)
		return (test2(ft_getunsigned(ap, lst)));
	else
		return (ft_itoa(ft_getsigned(ap, lst)));
}
