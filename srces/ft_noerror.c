/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:42:21 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 15:51:04 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

t_s			*ft_modifs(t_s *stru, char *line)
{
	ft_checkopt(stru, line);
	if (stru->step == 0)
		return (ft_stepz(stru, line));
	if (stru->step == 1)
		return (ft_stepo(stru, line));
	if (stru->step == 2)
		return (ft_stept(stru, line));
	if (stru->step == 3)
		return (ft_stepth(stru));
	write(2, "ERROR", 5);
	exit(1);
	return (stru);
}

int			**ft_initint(int **tab)
{
	if ((tab[0] = (int*)malloc(sizeof(int) * 2)) == NULL)
		return (NULL);
	tab[0][0] = 0;
	tab[0][1] = '\0';
	if ((tab[1] = (int*)malloc(sizeof(int) * 2)) == NULL)
		return (NULL);
	tab[1][0] = 0;
	tab[0][1] = '\0';
	return (tab);
}

void		ft_tiret(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			write(2, "ERROR", 5);
			exit(1);
		}
		i++;
	}
}

int			ft_noerror(t_s *stru)
{
	if (stru->start == 3)
		return (1);
	return (1);
}
