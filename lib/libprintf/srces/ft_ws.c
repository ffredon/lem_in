/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:53:57 by fredon            #+#    #+#             */
/*   Updated: 2016/01/21 10:45:06 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static wchar_t	*ft_wreduce(wchar_t *wstr, t_list *lst)
{
	wchar_t	*p;
	size_t	j;
	int		i;

	if ((p = (wchar_t*)malloc(sizeof(p) * (lst->prec + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	p[lst->prec] = '\0';
	while (j < (unsigned long)lst->prec)
	{
		j = j + ft_wlength(wstr[i]);
		if (j <= (unsigned long)lst->prec)
			p[i] = wstr[i];
		i++;
	}
	free(wstr);
	return (p);
}

static int		ft_wmorefield(int i, t_list *lst)
{
	while (lst->field > i)
	{
		if (lst->flag2)
		{
			ft_putchar('0');
		}
		else if (!lst->flag4)
			ft_putchar(' ');
		i++;
	}
	return (i);
}

static t_list	*ft_wnull(t_list *lst)
{
	write(1, "(null)", 6);
	lst->len = lst->len + 6;
	return (lst);
}

static wchar_t	*ft_wassign(wchar_t *wstr, wchar_t *tmp)
{
	int		i;

	i = 0;
	if (wstr)
	{
		while (wstr[i])
		{
			tmp[i] = wstr[i];
			i++;
		}
		tmp[i] = wstr[i];
		return (tmp);
	}
	return (NULL);
}

t_list			*ft_longs(va_list *ap, t_list *lst)
{
	wchar_t		*wstr;
	size_t		j;
	wchar_t		*tmp;

	if ((wstr = va_arg(*ap, int*)) == NULL && lst->field == 0)
		return (ft_wnull(lst));
	if ((tmp = (wchar_t *)malloc(sizeof(tmp) * (ft_wstrlen(wstr) + 1))) == NULL)
	{
		lst->len = -1;
		return (lst);
	}
	tmp = ft_wassign(wstr, tmp);
	j = ft_wstrlen(tmp);
	if (lst->prece && lst->prec < (int)j)
		tmp = ft_wreduce(tmp, lst);
	j = ft_wstrlen(tmp);
	if (lst->field > (int)j)
		j = ft_wmorefield(j, lst);
	ft_putwstr(tmp);
	ft_wminus(j, tmp, lst);
	lst->len = lst->len + (int)j;
	free(tmp);
	return (lst);
}
