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

NAME = fdf
BONUS_NAME = fdf_bonus

SRCS = 	main.c \
		read_file.c \
		read_file_aux.c \
		read_file_aux2.c \
		draw.c \
		render.c \
		fdf_color.c \
		init_enviro.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_printf.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_itoa_base.c \
		ft_itoa.c \
		ft_pr_hexa.c \
		ft_pr_letters.c \
		ft_pr_number.c \
		ft_split.c \
		ft_bzero.c

BONUS_SRCS = main_bonus.c \
			fdf_bonus.c \
			fdf_color.c \
			read_file.c \
			read_file_aux.c \
			read_file_aux2.c \
			draw.c \
			render.c \
			init_enviro.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_printf.c \
			ft_strlen.c \
			ft_atoi.c \
			ft_itoa_base.c \
			ft_itoa.c \
			ft_pr_hexa.c \
			ft_pr_letters.c \
			ft_pr_number.c \
			ft_split.c \
			ft_bzero.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.
LDFLAGS = -lm
MLX = -lmlx -lXext -lX11 -lbsd
# MLX = -L./libs -lmlx -L/usr/X11R6/lib -lXext -lX11 -lbsd

OBJ_DIR = build

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(MLX) $(LDFLAGS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -o $(BONUS_NAME) $(MLX) $(LDFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean 
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
