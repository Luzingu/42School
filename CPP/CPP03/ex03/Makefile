# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 11:13:23 by aluzingu          #+#    #+#              #
#    Updated: 2025/01/27 11:13:24 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	diamond_trap

CC		=	c++

FLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	main.cpp \
			ClapTrap.cpp\
			ScavTrap.cpp\
			FragTrap.cpp\
			DiamondTrap.cpp

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
