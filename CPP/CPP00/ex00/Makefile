NAME = megaphone

SRC = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

FLAGS = -Werror -Wextra -Wall

CC = c++

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJS)


fclean: clean
		rm -f $(NAME)

re: fclean all

