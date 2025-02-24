# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 10:27:20 by aluzingu          #+#    #+#              #
#    Updated: 2025/01/29 10:27:21 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	abstract

CC		=	c++

FLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	= 	main.cpp \
			Animal.cpp \
			Dog.cpp \
			Cat.cpp\
			Brain.cpp\
			WrongAnimal.cpp\
			WrongCat.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp
	c++  $(FLAGS)  -c -o $@ $<

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
