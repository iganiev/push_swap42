# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 12:39:00 by iganiev           #+#    #+#              #
#    Updated: 2023/07/25 17:25:56 by iganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

SRC = 	push_swap.c stack_a_op.c utils.c stack_op.c stack_b_op.c stack_ab_op.c \
		sorting_algorithm.c sorting_utils.c parsing.c stack_utils.c parsing_utils.c\
		push_swap_function.c ps_sort_utils.c\

OBJ = $(SRC:.c=.o)

BONUS =	checker.c stack_a_op.c utils.c stack_op.c stack_b_op.c stack_ab_op.c \
		sorting_algorithm.c sorting_utils.c parsing.c stack_utils.c parsing_utils.c\
		push_swap_function.c ps_sort_utils.c bonus_utils.c\

OBJB = $(BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 
#-fsanitize=address

LIB = cd libft && make

MYPRINTF = cd printf42 && make

$(NAME): $(OBJ)
		$(LIB)
		$(MYPRINTF)
		cc $(OBJ)  $(CFLAGS) libft/libft.a printf42/libftprintf.a -o $(NAME)

all: $(NAME)

bonus: $(OBJ) $(OBJB) 
	$(LIB)
	$(MYPRINTF)
	cc $(OBJB)  $(CFLAGS) libft/libft.a printf42/libftprintf.a -o $(BONUS_NAME)

clean:
		rm -f $(OBJ) $(OBJB)
		cd libft && make clean
		cd printf42 && make clean

fclean: clean
		rm -f $(NAME)
		rm -f $(BONUS_NAME)
		cd libft && make fclean
		cd printf42 && make fclean

re:		fclean all
		cd libft && make fclean && make all
		cd printf42 && make fclean && make all

.PHONY:	all clean fclean re bonus