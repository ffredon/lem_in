/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 09:23:08 by fredon            #+#    #+#             */
/*   Updated: 2016/01/14 14:43:08 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

char	*ft_assign(char *str, char *tmp)
{
	int		i;

	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = str[i];
	return (tmp);
}

int		ft_null(void)
{
	ft_putstr("(null)");
	return (6);
}

int		ft_printstr(va_list ap, t_list *lst)
{
	char	*str;
	int		i;
	char	*tmp;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (ft_null());
	if (tmp = (char*)malloc(sizeof(*tmp) * (ft_strlen(str) + 1)) == NULL)
		return (-1);
	tmp = ft_assign(str, tmp);
	i = ft_strlen(tmp);
	if (lst->prece && lst->prec < i)
		ft_reduce(tmp, i, lst);
	if (lst->field > i)
		ft_morefield(i, lst);
	ft_putstr(tmp);
	while ((lst->flag4) && (i > ft_strlen(tmp)))
	{
		ft_putchar(' ');
		i--;
	}
	free(tmp);
	return (i);
}
