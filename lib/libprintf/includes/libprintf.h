/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 03:29:00 by fredon            #+#    #+#             */
/*   Updated: 2016/02/15 10:35:10 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <wchar.h>
# include <stddef.h>

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BOLDBLACK "\033[1m\033[30m"
# define BOLDRED "\033[1m\033[31m"
# define BOLDGREEN "\033[1m\033[32m"
# define BOLDYELLOW "\033[1m\033[33m"
# define BOLDBLUE "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN "\033[1m\033[36m"
# define BOLDWHITE "\033[1m\033[37m"

typedef struct		s_list
{
	int				flag1;
	int				flag2;
	int				flag3;
	int				flag4;
	int				flag5;
	int				flag6;
	int				field;
	int				prece;
	int				precp;
	int				prec;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				j;
	int				t;
	int				z;
	int				lll;
	int				trail;
	int				cap;
	int				opt;
	int				len;
}					t_list;

size_t				ft_wlength(int i);
void				ft_putwchar(wchar_t chr);
size_t				ft_wstrlen(int *wstr);
t_list				*ft_p(va_list *ap, t_list *lst);
t_list				*ft_doarg(char *s, int i, va_list *ap, t_list *lst);
t_list				*ft_u(va_list *ap, char *s, int i, t_list *lst);
t_list				*ft_o(va_list *ap, char *s, int i, t_list *lst);
t_list				*ft_c(va_list *ap, char *s, int i, t_list *lst);
t_list				*ft_longs(va_list *ap, t_list *lst);
t_list				*ft_s(va_list *ap, char *s, int i, t_list *lst);
t_list				*ft_x(va_list *ap, char *s, int i, t_list *lst);
t_list				*ft_percent(char *s, int i, t_list *lst);
void				ft_capitalize(char *str);
int					ft_putchar(char c);
void				ft_putstr(char *str, t_list *lst);
void				ft_sign(char *p, t_list *lst);
void				ft_minus(int i, char *p, t_list *lst);
void				ft_plus(char *p, t_list *lst);
char				*ft_specx(char *p, t_list *lst);
int					ft_morefield(int i, t_list *lst, char *p);
char				*ft_grow(char *p, int i, t_list *lst);
int					ft_strlen2(char *str);
long double			ft_getfloat(va_list *ap, t_list *lst);
unsigned long long	ft_getunsigned(va_list *ap, t_list *lst);
long long			ft_getsigned(va_list *ap, t_list *lst);
char				*ft_it(va_list *ap, t_list *lst);
char				*ft_itoa(long long n);
char				*ft_spec(char *p, t_list *lst, int j);
t_list				*ft_d(va_list *ap, char *s, int i, t_list *lst);
t_list				*ft_chooseprint(va_list *ap, char *s, int i, t_list *lst);
t_list				*ft_modif(char *s, int i, va_list *ap, t_list *lst);
t_list				*ft_prec(char *s, int i, va_list *ap, t_list *lst);
t_list				*ft_flag(char *s, int i, va_list *ap, t_list *lst);
int					ft_find(char *s, int i, t_list *lst);
t_list				*ft_path(char *s, int i, va_list *ap, t_list *lst);
t_list				*ft_init(t_list *lst);
int					ft_printf(const char *format, ...);
void				ft_putwstr(wchar_t *w);
t_list				*ft_fieldarg(char *s, int i, va_list *ap, t_list *lst);
void				ft_wminus(int i, wchar_t *wstr, t_list *lst);

#endif
