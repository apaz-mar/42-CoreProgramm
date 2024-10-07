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

MY_SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

MY_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

MY_HEADERS = libft.h

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

CUR_DIR = $(shell pwd)

CC = gcc

RM = rm -f

AR = ar rc

LIB = ranlib

MY_OBJECTS = $(MY_SOURCES:.c=.o)

BONUS_OBJECTS = $(MY_BONUS:.c=.o)

$(NAME): $(MY_OBJECTS) $(BONUS_OBJECTS)
	$(AR) $@ $^
	$(LIB) $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(CUR_DIR) -c $< -o $@

all: $(NAME)

bonus: $(NAME)

clean: 
	$(RM) $(MY_OBJECTS) $(BONUS_OBJECTS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus


