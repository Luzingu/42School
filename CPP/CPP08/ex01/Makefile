# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 12:18:37 by aluzingu          #+#    #+#              #
#    Updated: 2025/02/27 12:21:30 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Span.cpp

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