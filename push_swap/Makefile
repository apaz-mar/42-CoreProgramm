# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 14:10:09 by apaz-mar          #+#    #+#              #
#    Updated: 2024/05/06 13:40:46 by apaz-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MY_SOURCES = ft_itoa_base.c ft_itoa.c ft_pr_hexa.c ft_pr_letters.c ft_pr_number.c ft_printf.c ft_strlen.c

MY_HEADERS = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

CUR_DIR = $(shell pwd)

CC = cc

RM = rm -f

AR = ar rc

LIB = ranlib

MY_OBJECTS = $(MY_SOURCES:.c=.o)

$(NAME): $(MY_OBJECTS)
	$(AR) $@ $^
	$(LIB) $@

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(CUR_DIR) -c $< -o $@

clean: 
	$(RM) $(MY_OBJECTS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


