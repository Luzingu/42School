# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 11:07:03 by aluzingu          #+#    #+#              #
#    Updated: 2025/01/27 11:07:04 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	serena

CC		=	c++

FLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	main.cpp \
			ClapTrap.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp
	c++    -c -o $@ $<

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
