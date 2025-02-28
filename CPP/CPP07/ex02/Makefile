# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 19:17:38 by aluzingu          #+#    #+#              #
#    Updated: 2025/02/25 11:00:06 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

CC = c++

FLAGS = -Werror -Wextra -Wall -std=c++98

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all