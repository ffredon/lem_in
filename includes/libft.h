/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 08:48:33 by fredon            #+#    #+#             */
/*   Updated: 2016/02/18 14:29:43 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
void				*ft_memset(void *str, int value, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, const char *src);

int					get_next_line(int fd, char **line);

#endif
