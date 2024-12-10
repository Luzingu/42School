NAME = phone_book

FLAGS = -Wall -Wextra -Werror

CC = c++

SRCS = src/main.cpp \
		src/contact.cpp \
		src/book.cpp \


OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean: rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
