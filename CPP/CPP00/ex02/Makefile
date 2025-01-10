# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 12:27:42 by aluzingu          #+#    #+#              #
#    Updated: 2024/12/11 12:27:44 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp \
	tests.cpp

OBJS = $(SRCS.:cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
