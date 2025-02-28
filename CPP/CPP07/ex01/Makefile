# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 18:17:23 by aluzingu          #+#    #+#              #
#    Updated: 2025/02/24 18:32:04 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter

CC = c++

FLAGS = -Werror -Wall -Wextra -std=c++98

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
