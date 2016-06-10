/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:56:15 by fredon            #+#    #+#             */
/*   Updated: 2016/01/19 15:00:55 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"
#include <stdio.h>

static char	*ft_do(char *p, int i, t_list *lst, char *str)
{
	int		j;
	int		k;

	str[lst->prec] = '\0';
	str[0] = '-';
	j = 1;
	lst->prec--;
	k = i - 1;
	while (lst->prec > k)
	{
		str[j] = '0';
		j++;
		lst->prec--;
	}
	while (k >= 0)
	{
		if (p[lst->prec - k] != '-')
		{
			str[j] = p[lst->prec - k];
			j++;
		}
		k--;
	}
	free(p);
	return (str);
}

static char	*ft_do2(char *p, int i, t_list *lst, char *str)
{
	int		j;
	int		k;

	str[lst->prec + 1] = '\0';
	str[0] = '0';
	str[1] = 'x';
	j = 2;
	lst->prec = lst->prec - 2;
	k = i - 1;
	while (lst->prec > k)
	{
		str[j] = '0';
		j++;
		lst->prec--;
	}
	while (k >= 0)
	{
		p[lst->prec - k] == 'x' ? str[j] = '0' : 0;
		p[lst->prec - k] != 'x' ? str[j] = p[lst->prec - k] : 0;
		j++;
		k--;
	}
	free(p);
	return (str);
}

static char	*ft_grow2(char *p, int i, t_list *lst)
{
	char	*str;

	lst->prec++;
	if ((str = (char*)malloc(sizeof(*str) * (lst->prec + 1))) == NULL)
		return (NULL);
	if (p[0] == '-')
		return (ft_do(p, i, lst, str));
	return (ft_do2(p, i, lst, str));
}

char		*ft_grow(char *p, int i, t_list *lst)
{
	char	*str;
	int		j;
	int		k;

	if (p[0] == '-' || (p[0] == '0' && p[1] == 'x'))
		return (ft_grow2(p, i, lst));
	j = 0;
	k = i;
	if ((str = (char*)malloc(sizeof(*str) * (lst->prec + 1))) == NULL)
		return (NULL);
	str[lst->prec] = '\0';
	while (lst->prec > k)
	{
		str[j] = '0';
		j++;
		lst->prec--;
	}
	while (k >= 0)
	{
		str[j] = p[lst->prec - k];
		j++;
		k--;
	}
	free(p);
	return (str);
}
