CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = refPtrDiff
SRCS = main.cpp
OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

listC:
	@find -wholename "./srcs/*.cpp" | cut -c 3- | tr '\n' ' '
