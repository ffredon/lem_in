# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fredon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/23 04:51:30 by fredon            #+#    #+#              #
#    Updated: 2016/02/15 11:45:54 by fredon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(LIBA)
LIBA = libftprintf.a

HPATH = -I includes
SRC = srces/ft_printf.c \
	  srces/tools.c \
	  srces/ft_path.c \
	  srces/ft_flag.c \
	  srces/ft_prec.c \
	  srces/ft_modif.c \
	  srces/ft_doarg.c\
	  srces/ft_chooseprint.c \
	  srces/ft_d.c \
	  srces/ft_getarg.c \
	  srces/tools.c \
	  srces/ft_grow.c \
	  srces/ft_morefield.c \
	  srces/ft_plus.c \
	  srces/ft_capitalize.c \
	  srces/ft_it.c \
	  srces/ft_x.c \
	  srces/ft_s.c \
	  srces/ft_ws.c \
	  srces/ft_c.c \
	  srces/ft_o.c \
	  srces/ft_u.c \
	  srces/ft_p.c \
	  srces/ft_wutils.c \
	  srces/ft_percent.c
CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -c $(SRC)
	@(ar -rc $(NAME) $(OBJ))
	@(ranlib $(NAME))

clean:
	@(rm -f $(OBJ))
	@(rm -f ft_printf.o tools.o ft_path.o ft_argpath.o ft_capitalize.o\
		ft_doarg.o ft_argon.o ft_prec.o ft_modif.o ft_chooseprint.o\
		ft_d.o ft_getarg.o tools.o ft_grow.o ft_morefield.o ft_plus.o\
		ft_flag.o ft_it.o ft_percent.o ft_x.o ft_s.o ft_ws.o ft_c.o\
		ft_o.o ft_u.o ft_p.o ft_wutils.o)
fclean: clean
	@(rm -f $(NAME))

re: fclean all
