/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:12:26 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 11:30:27 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

int			ft_antlength(t_s *stru)
{
	int		size;
	int		tmp;

	size = 0;
	tmp = stru->ants;
	while (tmp)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

t_opt		*ft_initopt(t_s *stru)
{
	t_opt	*opt;

	if ((opt = (t_opt*)malloc(sizeof(t_opt))) == NULL)
		return (NULL);
	opt->color = 0;
	opt->pres = 0;
	opt->path = 0;
	opt->number = 0;
	opt->silence = 0;
	opt->length = 0;
	opt->ants = 0;
	stru->opt = opt;
	return (opt);
}

void		ft_checkopt(t_s *stru, char *line)
{
	if (!ft_strcmp(line, "##color"))
		stru->opt->color = 1;
	if (!ft_strcmp(line, "##pres"))
		stru->opt->pres = 1;
	if (!ft_strcmp(line, "##path"))
		stru->opt->path = 1;
	if (!ft_strcmp(line, "##number"))
		stru->opt->number = 1;
	if (!ft_strcmp(line, "##silence"))
		stru->opt->silence = 1;
}

t_s			*ft_test(t_path *path, t_s *stru)
{
	int		i;

	i = 0;
	while (path->places->name[i])
		i++;
	if (i > stru->opt->length)
		stru->opt->length = i;
	return (stru);
}

t_s			*ft_getlength(t_s *stru)
{
	t_path		*path;
	t_path		*tmp;

	path = stru->path;
	if (stru->opt->path && !stru->opt->silence)
		ft_optpath(stru);
	while (1)
	{
		stru = ft_test(path, stru);
		tmp = path;
		while (tmp->path)
		{
			tmp = tmp->path;
			stru = ft_test(tmp, stru);
		}
		if (path->next)
			path = path->next;
		else
			break ;
	}
	if (stru->opt->pres == 0)
		stru->opt->length = 0;
	return (stru);
}
