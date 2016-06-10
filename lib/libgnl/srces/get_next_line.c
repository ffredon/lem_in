/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:13:51 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 09:20:04 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static int		ft_isnline(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

static int		ft_read_buff(int fd, char **read_buffer)
{
	char	*buf;
	int		ret;

	buf = ft_strnew(BUFF_SIZE);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret >= 0)
		*read_buffer = ft_strjoin(*read_buffer, buf);
	free(buf);
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static char	*buffer = "";
	char		*readb;
	int			ret;
	int			i;

	readb = ft_strnew(BUFF_SIZE);
	ret = 1;
	if (!*buffer)
		buffer = ft_strnew(BUFF_SIZE);
	readb = ft_strjoin(readb, buffer);
	while ((i = ft_isnline(readb)) < 0 && ret > 0)
		ret = ft_read_buff(fd, &readb);
	if (ret >= 0)
	{
		i = ((!ret && i == -1) ? ft_strlen(readb) : ft_isnline(readb));
		*line = ft_strsub(readb, 0, (size_t)i);
		ft_strcpy(buffer, ft_strsub(readb, (size_t)i + 1, ft_strlen(readb)));
		free(readb);
		return (ret != 0);
	}
	free(readb);
	return (-1);
}
