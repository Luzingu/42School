# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mebaptis <mebaptis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:06:51 by mebaptis          #+#    #+#              #
#    Updated: 2025/01/21 16:19:54 by mebaptis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

INC_DIR = include/
MLX_DIR = ./../minilibx-linux
LIBFT_DIR = ./libft

MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS =	src/main.c\
		src/utils/ft_cmp.c\
		src/utils/ft_num_split.c\
		src/utils/ft_free.c\
		src/utils/utils.c\
		src/draw/draw.c\
		src/draw/player_position.c\
		src/draw/key_event.c\
		src/draw/ray_casting.c\
		src/read_map/read_file.c\
		src/read_map/read_map.c\
		src/read_map/read_date.c\
		src/read_map/file_validator.c\
		src/read_map/valid_map.c

OBJS = $(SRCS:.c=.o)

CC = cc
##-Wall -Wextra -Werror 
CFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR)/include -g
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
