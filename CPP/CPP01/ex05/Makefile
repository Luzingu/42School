# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 17:29:17 by aluzingu          #+#    #+#              #
#    Updated: 2025/01/09 17:29:18 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	harl

CC		=	c++

FLAGS	=	-Werror -Wextra -Wall -std=c++98

SRCS	=	main.cpp\
			Harl.cpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean: rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: all fclean


