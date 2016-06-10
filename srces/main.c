/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:13:12 by fredon            #+#    #+#             */
/*   Updated: 2016/02/27 13:13:44 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"
#include "lemin.h"

int		main(int argc, char **argv)
{
	if (argc != 1 || argv[1])
	{
		write(2, "ERROR", 5);
		return (0);
	}
	ft_start(0);
	return (0);
}
