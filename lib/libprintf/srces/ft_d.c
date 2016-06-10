/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:36:39 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:32:45 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static int	ft_nbrlen(long long n)
{
	int			i;
	long long	nb;

	i = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return ((n < 0) ? i + 1 : i);
}

char		*ft_itoa(long long n)
{
	long long			val;
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
			str[len] = (n < 0) ? (n % 10) * -1 + 48 : (n % 10) + 48;
			n = n / 10;
		}
		if (val < 0)
			str[0] = '-';
	}
	return (str);
}

static char	*ft_test(char *p, t_list *lst)
{
	char	*str;
	int		len;

	if (p[0] == '-' && lst->flag2 && lst->field > ft_strlen2(p))
	{
		len = ft_strlen2(p);
		if ((str = (char*)malloc(sizeof(*str) * len)) == 0)
			return (NULL);
		len--;
		while (len + 1)
		{
			str[len] = p[len + 1];
			len--;
		}
		free(p);
		return (str);
	}
	return (p);
}

char		*ft_spec(char *p, t_list *lst, int j)
{
	if (j == 1 && p[0] == '0' && lst->prec == 0 && lst->prece)
		p[0] = '\0';
	return (p);
}

t_list		*ft_d(va_list *ap, char *s, int i, t_list *lst)
{
	char		*p;
	int			j;

	lst->opt++;
	if (lst->prece)
		lst->flag2 = 0;
	s[i] == 'D' ? lst->l = 1 : 0;
	p = ft_it(ap, lst);
	j = ft_strlen2(p);
	if ((j < lst->prec) || ((j <= lst->prec) && (p[0] == '-')))
		p = ft_grow(p, j, lst);
	p = ft_spec(p, lst, j);
	j = ft_strlen2(p);
	if (p[0] != '-' && (lst->flag3 || lst->flag5))
		j++;
	ft_sign(p, lst);
	if (lst->field > j)
		j = ft_morefield(j, lst, p);
	ft_plus(p, lst);
	p = ft_test(p, lst);
	ft_putstr(p, lst);
	ft_minus(j, p, lst);
	free(p);
	lst->len = lst->len + j;
	return (lst);
}
