# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iganiev <g.ibrogim98@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 12:39:00 by iganiev           #+#    #+#              #
#    Updated: 2023/07/14 08:44:20 by iganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	push_swap.c stack_a_op.c utils.c stack_op.c stack_b_op.c stack_ab_op.c \
		sorting_algorithm.c sorting_utils.c parsing.c\

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

LIB = cd libft && make

MYPRINTF = cd printf42 && make

$(NAME): $(OBJ)
		$(LIB)
		$(MYPRINTF)
		gcc $(OBJ)  $(CFLAGS) libft/libft.a printf42/libftprintf.a -o $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJ)
		cd libft && make clean
		cd printf42 && make clean

fclean: clean
		rm -f $(NAME)
		cd libft && make fclean
		cd printf42 && make fclean

re:		fclean all
		cd libft && make fclean && make all
		cd printf42 && make fclean && make all

.PHONY:	all clean fclean re