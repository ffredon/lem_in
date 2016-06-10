/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instepth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 11:11:24 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 14:45:43 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

t_s			*ft_else(t_s *stru, t_path *path, t_path *path2)
{
	while (path)
	{
		while (path->over == 1 && path->next)
			path = path->next;
		if (path->over == 2 && (!(path = ft_suppath(stru, path)) ||
			path))
			break ;
		if (path->over == 1 && !path->next)
			break ;
		if (path->over != 1)
			path2 = ft_inter(path, stru);
		if ((path->over == 1 || ((path2) && path2->over == 1)) &&
			ft_algo(stru, path2))
		{
			path->length = path2->length;
			path2 = ft_findover(path, path2);
			path->over = 1;
		}
		if (path->next)
			path = path->next;
		else
			break ;
	}
	return (stru);
}

t_s			*ft_instepth(t_s *stru, t_path *path, t_path *path2)
{
	while (!ft_done(stru))
	{
		path = stru->path;
		stru = ft_else(stru, path, path2);
	}
	if (ft_done(stru) == 2)
	{
		write(2, "ERROR", 5);
		exit(1);
	}
	return (stru);
}
