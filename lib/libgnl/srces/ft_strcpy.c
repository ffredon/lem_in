/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flourme <flourme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:35:57 by flourme           #+#    #+#             */
/*   Updated: 2015/12/08 16:58:55 by flourme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	ft_memset(dst, '\0', ft_strlen(dst) + 1);
	return (ft_strncpy(dst, src, ft_strlen(src) + 1));
}
