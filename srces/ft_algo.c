/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:26:55 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 14:08:31 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

int		ft_len(int *tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

int		*ft_newtab(int *tab, int x, t_path *path)
{
	int		*tmp;
	int		i;

	i = 0;
	if ((tmp = (int*)malloc(sizeof(int) * (ft_len(tab) + 2))) == NULL)
		return (NULL);
	if (x)
	{
		while (i < (ft_len(tab)) && (tmp[i] = tab[i]))
			i++;
		tmp[i] = path->length;
		tmp[ft_len(tab) + 1] = '\0';
	}
	else
	{
		while (i < (ft_len(tab) + 1) && !(tmp[i] = 0))
			i++;
		tmp[i] = '\0';
	}
	free(tab);
	return (tmp);
}

t_s		*ft_calc(t_s *stru, int x)
{
	int		*t1;
	int		*t0;

	t1 = stru->tab[1];
	t0 = stru->tab[0];
	if (!t0[x + 1])
		t1[x]++;
	else if ((t1[x] + t0[x]) > (t1[x + 1] + t0[x + 1]))
		stru = ft_calc(stru, x + 1);
	else
		t1[x]++;
	return (stru);
}

t_s		*ft_calculus(t_s *stru, t_path *path)
{
	int		x;

	x = 0;
	stru->tab[0] = ft_newtab(stru->tab[0], 1, path);
	stru->tab[1] = ft_newtab(stru->tab[1], 0, path);
	while (ft_sum(stru->tab[1]) < stru->ants)
		stru = ft_calc(stru, x);
	stru->start = stru->tab[1][0] + stru->tab[0][0] - 1;
	return (stru);
}

int		ft_algo(t_s *stru, t_path *path)
{
	if (stru->end == 2)
	{
		stru->end = 0;
		stru->start = stru->ants + path->length - 1;
		stru->tab[0][0] = path->length;
		stru->tab[1][0] = stru->ants;
	}
	else
	{
		if (path->length < stru->start)
			stru = ft_calculus(stru, path);
		else
		{
			path->over = 2;
			return (0);
		}
	}
	return (1);
}
