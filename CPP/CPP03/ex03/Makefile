NAME	=	open

CC		=	c++

FLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	main.cpp \
			ClapTrap.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

flclean: clean
		flclean all
