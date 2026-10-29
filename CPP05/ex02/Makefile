CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = formPls
SRCS = srcs/Bureaucrat.cpp srcs/AForm.cpp srcs/RobotomyRequestForm.cpp srcs/ShrubberyCreationForm.cpp srcs/main.cpp srcs/PresidentialPardonForm.cpp
INCLUDE_PATH = -Iincludes

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) $(INCLUDE_PATH) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(INCLUDE_PATH) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

listC:
	@find -wholename "./srcs/*.cpp" | cut -c 3- | tr '\n' ' '

