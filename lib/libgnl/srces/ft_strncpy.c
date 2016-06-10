/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:13:02 by fredon            #+#    #+#             */
/*   Updated: 2016/02/09 14:13:04 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*temp;

	temp = dest;
	while (n > 0 && *src != '\0')
	{
		*temp++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*temp++ = '\0';
		--n;
	}
	return (dest);
}
