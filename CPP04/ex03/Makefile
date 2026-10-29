CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fPIE
NAME = Materia
SRCS = srcs/AMateria.cpp srcs/Character.cpp srcs/Ice.cpp srcs/FireBall.cpp srcs/Curse.cpp srcs/Cure.cpp srcs/MateriaSource.cpp srcs/main.cpp
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

