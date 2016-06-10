# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fredon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 09:01:13 by fredon            #+#    #+#              #
#    Updated: 2016/02/16 09:06:55 by fredon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	srces/ft_memalloc.c \
			srces/ft_strcmp.c \
			srces/ft_strjoin.c \
			srces/ft_strncat.c \
			srces/ft_strnew.c \
			srces/get_next_line.c \
			srces/ft_memset.c \
			srces/ft_strlen.c \
			srces/ft_strncpy.c \
			srces/ft_strcpy.c \
			srces/ft_strsub.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.PHONY	:	re clean fclean all

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

%.o		:	%.c
		$(CC) $(CFLAGS) -o $@ -c $^ -I includes/

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re		:	fclean all
