# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 13:30:24 by aluzingu          #+#    #+#              #
#    Updated: 2025/01/09 13:30:26 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   un_violence

CC      =   c++

FLAGS   =   -Werror -Wextra -Wall -std=c++98

SRCS    =   main.cpp \
            HumanA.cpp \
            HumanB.cpp \
            Weapon.cpp

OBJS    =   $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
