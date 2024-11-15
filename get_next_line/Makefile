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

MY_SOURCES = get_next_line.c get_next_line_utils.c

MY_HEADERS = get_next_line.h

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

NAME = libgnl.a

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



