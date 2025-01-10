# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:11:15 by aluzingu          #+#    #+#              #
#    Updated: 2025/01/09 16:11:17 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    =   sed_losers

FLAGS   =   -Wall -Wextra -Werror -std=c++98

CC      =   c++

SRC     =   main.cpp

OBJS    =   $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
