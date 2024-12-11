# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 14:55:36 by aluzingu          #+#    #+#              #
#    Updated: 2024/12/11 14:55:38 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = c++

FLAGS = -Werror -Wextra -Wall

SRC = main.cpp \
	Zombie.cpp \
	randomChump.c

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
