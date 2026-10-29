CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Wouf
SRCS = srcs/Dog.cpp srcs/main.cpp srcs/Animal.cpp srcs/WrongAnimal.cpp srcs/Cat.cpp srcs/WrongCat.cpp
INCLUDE_PATH = -Iincludes

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) $(INCLUDE_PATH) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(INCLUDE_PATH) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

listC:
	@find -wholename "./srcs/*.cpp" | cut -c 3- | tr '\n' ' '

