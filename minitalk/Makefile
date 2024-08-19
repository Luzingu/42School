# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 16:55:14 by aluzingu          #+#    #+#              #
#    Updated: 2024/08/19 16:55:16 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
RM = rm -rf

SERVER = server
CLIENT = client

SV_SRCS = mandatory/server.c
SV_OBJS = $(SV_SRCS:.c=.o)

CLIENT_SRCS = mandatory/client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)


SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SV_SRCS_BONUS = bonus/server_bonus.c
SV_OBJS_BONUS = $(SV_SRCS_BONUS:.c=.o)

CLIENT_SRCS_BONUS = bonus/client_bonus.c
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
	$(MAKE) -C ./libft
	$(MAKE) bonus -C ./libft
	
$(PRINTF):
	$(MAKE) -C ./printf

$(SERVER): $(SV_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT) $(PRINTF) -o server

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(PRINTF) -o client

$(SERVER_BONUS): $(SV_OBJS_BONUS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SV_OBJS_BONUS) $(LIBFT) $(PRINTF) -o server_bonus

$(CLIENT_BONUS): $(CLIENT_OBJS_BONUS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS_BONUS) $(LIBFT) $(PRINTF) -o client_bonus
	
clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./printf
	$(RM) $(SV_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./printf
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all
