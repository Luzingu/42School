# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 12:26:16 by aluzingu          #+#    #+#              #
#    Updated: 2024/12/11 12:26:18 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phone_book

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = src/main.cpp \
		src/Contact.cpp \
		src/PhoneBook.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
