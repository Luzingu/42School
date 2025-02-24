# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 14:18:15 by aluzingu          #+#    #+#              #
#    Updated: 2025/02/24 14:34:26 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identity

CC = c++

FLAGS = -Werror -Wall -Wextra -std=c++98

SRCS = main.cpp ClassBase.cpp function.cpp

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