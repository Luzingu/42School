# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 11:19:27 by aluzingu          #+#    #+#              #
#    Updated: 2025/02/28 15:50:45 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CC = c++

FLAGS = -Werror -Wall -Wextra  -std=c++98

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