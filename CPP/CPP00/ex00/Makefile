# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 12:25:31 by aluzingu          #+#    #+#              #
#    Updated: 2024/12/11 12:25:35 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

FLAGS = -Werror -Wextra -Wall -std=c++98

CC = c++

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJS)


fclean: clean
		rm -f $(NAME)

re: fclean all

