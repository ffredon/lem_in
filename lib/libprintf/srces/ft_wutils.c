/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:17:41 by fredon            #+#    #+#             */
/*   Updated: 2016/01/21 10:41:14 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

void		ft_wminus(int i, wchar_t *wstr, t_list *lst)
{
	int		j;
	int		len;

	len = (int)ft_wstrlen(wstr);
	j = i;
	while ((lst->flag4) && (j > len))
	{
		ft_putchar(' ');
		j--;
	}
}

size_t		ft_wlength(int i)
{
	size_t	j;

	j = 0;
	if (i <= 0x7F)
		j++;
	else if (i <= 0x7FF)
		j += 2;
	else if (i <= 0xFFFF)
		j += 3;
	else if (i <= 0x10FFFF)
		j += 4;
	return (j);
}

size_t		ft_wstrlen(int *wstr)
{
	size_t	i;

	i = 0;
	if (wstr)
	{
		while (*wstr)
		{
			if (*wstr <= 0x7F)
				i++;
			else if (*wstr <= 0x7FF)
				i += 2;
			else if (*wstr <= 0xFFFF)
				i += 3;
			else if (*wstr <= 0x10FFFF)
				i += 4;
			wstr += 1;
		}
	}
	return (i);
}

void		ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putchar(chr);
	else if (chr <= 0x7FF)
	{
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar((chr >> 12) + 0xE0);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar((chr >> 18) + 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
}

void		ft_putwstr(wchar_t *wstr)
{
	while (*wstr != 0)
	{
		ft_putwchar(*wstr);
		wstr += 1;
	}
}
