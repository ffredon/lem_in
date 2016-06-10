/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:52:39 by fredon            #+#    #+#             */
/*   Updated: 2016/03/02 15:51:00 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct		s_opt
{
	int				color;
	int				pres;
	int				path;
	int				number;
	int				silence;
	int				length;
	int				ants;
}					t_opt;

typedef struct		s_l
{
	char			*str;
	struct s_l		*next;
	struct s_l		*first;
}					t_l;

typedef struct		s_p
{
	char			*name;
	int				x;
	int				y;
	struct s_p		*first;
	int				start;
	int				end;
	struct s_p		*next;
	t_l				*link;
}					t_p;

typedef struct		s_path
{
	t_p				*places;
	struct s_path	*path;
	struct s_path	*next;
	struct s_path	*first;
	struct s_path	*up;
	int				over;
	int				length;
}					t_path;

typedef struct		s_s
{
	char			*str;
	int				ants;
	int				start;
	int				end;
	int				step;
	int				**tab;
	t_p				*places;
	t_path			*path;
	t_opt			*opt;
}					t_s;

int					ft_noerror(t_s *stru);
t_s					*ft_modifs(t_s *stru, char *line);
t_l					*ft_initlink(t_l *link);
t_path				*ft_initpath(t_path *path);
t_p					*ft_initplaces(t_p *places);
int					**ft_initint(int **tab);
t_s					*ft_initstru(t_s *stru);
void				ft_start(int fd);
t_s					*ft_stepz(t_s *stru, char *line);
t_s					*ft_stepo(t_s *stru, char *line);
int					ft_countwords(char *line);
int					ft_wordsize(char *line);
char				*ft_getword(char *line);
t_s					*ft_takeplace(t_s *stru, char *line);
int					ft_equalplace(t_p *places, char *line);
char				*ft_gettdword(char *line);
char				*ft_getscdword(char *line);
int					ft_atoidel(char *str);
int					ft_istube(t_s *stru, char *line);
t_s					*ft_stept(t_s *stru, char *line);
int					ft_cmpname(t_s *stru, char *word);
int					ft_cmpname(t_s *stru, char *word);
int					ft_nolink(t_s *stru, char *line);
t_s					*ft_makelink(t_s *stru, char *line);
char				*ft_gtword(char *line);
char				*ft_gtscdword(char *line);
t_l					*ft_linkone(t_l *link, char *line);
t_l					*ft_linktwo(t_l *link, char *line);
t_l					*ft_getlink(t_l *link, t_l *next, char *word);
t_l					*ft_firstlink(t_l *link, char *word);
t_s					*ft_stepth(t_s *stru);
t_path				*ft_firstpath(t_s *stru, t_path *path, t_p *places);
t_path				*ft_pathfirst(t_path *path, t_l *link, t_s *stru);
t_path				*ft_nextpath(t_path *path, t_l *link, t_s *stru);
t_path				*ft_makepath(t_s *stru, t_path *path);
t_path				*ft_pathi(t_s *stru, t_path *path);
t_path				*ft_findover(t_path *path, t_path *path2);
void				ft_suppress(t_path *path);
void				ft_suppress2(t_path *path);
t_path				*ft_pathpath(t_path *path, t_s *stru, t_l *link);
t_path				*ft_inter(t_path *path, t_s *stru);
void				ft_destroy(t_path *next, t_path *path);
int					ft_supuseless(t_path *path);
void				ft_next(t_path *path);
t_path				*ft_suppathfst(t_s *stru, t_path *path);
t_path				*ft_suppath(t_s *stru, t_path *path);
int					ft_alrdyhere(t_s *stru, t_l *link, t_path *up);
int					ft_isfirst(t_path *path);
int					ft_algo(t_s *stru, t_path *path);
void				ft_printit(t_s *stru);
int					ft_sum(int *tab);
void				ft_destroy(t_path *next, t_path *path);
int					ft_up(t_p *places, t_path *path, t_l *link, t_s *stru);
t_path				*ft_pathinorm(t_path *path, t_l *link, t_s *stru);
t_s					*ft_linknorm(t_s *stru, t_l *link, t_p *places);
t_s					*ft_instepth(t_s *stru, t_path *path, t_path *path2);
int					ft_done(t_s *stru);
t_opt				*ft_initopt(t_s *stru);
void				ft_checkopt(t_s *stru, char *line);
int					ft_antlength(t_s *stru);
t_s					*ft_getlength(t_s *stru);
void				ft_optpath(t_s *stru);
char				*ft_color(t_s *stru, char *str, t_p *places);
char				*ft_colori(t_s *stru, char *str, t_p *places);
void				ft_tiret(char *str);
int					main(int argc, char **argv);

#endif
