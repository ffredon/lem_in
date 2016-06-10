/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 08:56:23 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:32:58 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static char		*ft_assign(char *str, char *tmp)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = str[i];
		return (tmp);
	}
	return (NULL);
}

static char		*ft_reduce(char *str, int i, t_list *lst)
{
	char	*p;

	if ((p = (char*)malloc(sizeof(p) * (lst->prec + 1))) == NULL)
		return (NULL);
	p[lst->prec] = '\0';
	i = 0;
	while (i < lst->prec)
	{
		p[i] = str[i];
		i++;
	}
	return (p);
}

static t_list	*ft_null(t_list *lst)
{
	char	*tmp;
	int		j;

	tmp = "(null)";
	j = 6;
	if (lst->prece && lst->prec < j)
	{
		tmp = ft_reduce(tmp, j, lst);
		j = ft_strlen2(tmp);
	}
	if (lst->field > j)
		j = ft_morefield(j, lst, tmp);
	ft_putstr(tmp, lst);
	ft_minus(j, tmp, lst);
	lst->len = lst->len + j;
	return (lst);
}

static t_list	*ft_error(t_list *lst)
{
	lst->len = -1;
	return (lst);
}

t_list			*ft_s(va_list *ap, char *s, int i, t_list *lst)
{
	char	*str;
	int		j;
	char	*tmp;

	lst->opt++;
	s[i] == 'S' ? lst->l = 1 : 0;
	if (lst->l)
		return (ft_longs(ap, lst));
	if ((str = va_arg(*ap, char *)) == NULL)
		return (ft_null(lst));
	if ((tmp = (char*)malloc(sizeof(*tmp) * (ft_strlen2(str) + 1))) == NULL)
		return (ft_error(lst));
	tmp = ft_assign(str, tmp);
	j = ft_strlen2(tmp);
	if (lst->prece && lst->prec < j)
		tmp = ft_reduce(tmp, j, lst);
	j = ft_strlen2(tmp);
	if (lst->field > j)
		j = ft_morefield(j, lst, tmp);
	ft_putstr(tmp, lst);
	ft_minus(j, tmp, lst);
	free(tmp);
	lst->len = lst->len + j;
	return (lst);
}
