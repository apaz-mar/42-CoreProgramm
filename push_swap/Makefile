# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 14:10:09 by apaz-mar          #+#    #+#              #
#    Updated: 2024/10/23 17:11:23 by apaz-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILES = auxiliaries.c \
		auxiliaries2.c \
		auxiliaries3.c \
		auxiliary_checks.c \
		auxiliary_checks2.c \
		ft_atoi.c \
		ft_atol.c \
		ft_calloc.c \
		ft_isdigit.c \
		ft_itoa_base.c \
		ft_itoa.c \
		ft_pr_hexa.c \
		ft_pr_letters.c \
		ft_pr_number.c \
		ft_printf.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		move_cheapest_check_ops_1.c \
		move_cheapest_check_ops_2.c \
		move_cheapest.c \
		move_stack_a.c \
		move_stack_a2.c \
		move_stack_a3.c \
		push_swap_short.c \
		push_swap.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

OBJ_DIR = build

OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean: 
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

