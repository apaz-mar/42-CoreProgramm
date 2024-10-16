# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 14:10:09 by apaz-mar          #+#    #+#              #
#    Updated: 2024/05/06 12:21:06 by apaz-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MY_SOURCES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

MY_HEADERS = includes

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

CUR_DIR = $(shell pwd)

CC = gcc

RM = rm -f

AR = ar rc

LIB = ranlib

MY_OBJECTS = $(MY_SOURCES:.c=.o)

$(NAME): $(MY_OBJECTS)
	$(AR) $@ $^
	$(LIB) $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(MY_HEADERS) -c $< -o $@

all: $(NAME)

clean: 
	$(RM) $(MY_OBJECTS) 

fclean: clean 
	$(RM) $(NAME)

re: fclean all


