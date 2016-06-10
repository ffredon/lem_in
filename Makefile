# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fredon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 10:00:16 by fredon            #+#    #+#              #
#    Updated: 2016/03/02 10:49:54 by fredon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in

SRCS	=	srces/main.c \
			srces/ft_noerror.c \
			srces/ft_stepz.c \
			srces/ft_stepo.c \
			srces/ft_words.c \
			srces/ft_takeplace.c \
			srces/ft_placeutils.c \
			srces/ft_stept.c \
			srces/ft_three.c \
			srces/ft_links.c \
			srces/ft_stepth.c \
			srces/ft_makepath.c \
			srces/ft_pathpath.c \
			srces/ft_suppathfst.c \
			srces/ft_algo.c \
			srces/ft_printit.c \
			srces/ft_norm.c \
			srces/ft_instepth.c \
			srces/ft_opt.c \
			srces/ft_optpath.c \
			srces/ft_start.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

LIBFT	=	libft.a

LIBP	=	libftprintf.a

LIBDIR	=	lib/libgnl

PDIR	=	lib/libprintf

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.PHONY	:	re clean fclean all

all		:	$(NAME)

$(NAME)	:	libft libp $(OBJS)
		@($(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBDIR)/$(LIBFT)  $(PDIR)/$(LIBP)) 

%.o		:	%.c
		$(CC) $(CFLAGS) -o $@ -c $^ -I includes/

libft	:
		make -C $(LIBDIR)

libcl	:
		make -C $(LIBDIR) clean

libfcl	:
		make -C $(LIBDIR) fclean

libp	:
		make -C $(PDIR)

pcl		:
		make -C $(PDIR) clean

pfcl	:
		make -C $(PDIR) fclean

clean	: libcl pcl
		$(RM) $(OBJS)

fclean	:	libfcl pfcl
		$(RM) $(OBJS)
		$(RM) $(NAME)

re		: fclean all
