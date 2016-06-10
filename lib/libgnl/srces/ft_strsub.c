/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:13:35 by fredon            #+#    #+#             */
/*   Updated: 2016/02/09 14:13:37 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int index, size_t len)
{
	char			*result;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	result = ft_strnew(len);
	if (result)
	{
		while (i < len)
		{
			result[i] = s[(unsigned int)i + index];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
