NAME = cub3D

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

SRCS = main.c
OBJS = $(SRCS:.c=.o)

INC = -I$(LIBFT_DIR) -I$(MLX_DIR)
 
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean: 
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

%.o: %.c
	$(CC) $(FLAGS) $(INC) -c $< -o $@