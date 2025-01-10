# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 15:28:18 by aluzingu          #+#    #+#              #
#    Updated: 2025/01/10 15:28:20 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	canonical_form

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp \
			Fixed.cpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
