CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -g3
NAME = span
SRCS = srcs/main.cpp srcs/Span.cpp
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
	rm -rf $(NAME) *.json .cache

re: fclean all

listC:
	@find -wholename "./srcs/*.cpp" | cut -c 3- | tr '\n' ' '

