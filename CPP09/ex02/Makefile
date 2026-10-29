CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = PmergeM
SRCS = srcs/main.cpp srcs/ListSort.cpp  

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME) *.json .cache vgcore.*

re: fclean all

listC:
	@find -wholename "./srcs/*.cpp" | cut -c 3- | tr '\n' ' ' | xclip -selection clipboard

