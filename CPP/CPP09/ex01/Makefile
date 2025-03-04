# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 18:26:44 by aluzingu          #+#    #+#              #
#    Updated: 2025/03/03 19:09:08 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CC = c++

FLAGS = -Werror -Wextra -Wall

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
