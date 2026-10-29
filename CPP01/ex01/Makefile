CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Horde
SRCS = Zombie.cpp main.cpp zombieHorde.cpp
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
	@find -wholename "*.cpp" | cut -c 3- | tr '\n' ' '
