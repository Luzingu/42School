NAME = ACCOUNT

CC = c++

FLAGS = 

SRCS = Account.cpp \
	tests.cpp

OBJS = $(SRCS.:cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all