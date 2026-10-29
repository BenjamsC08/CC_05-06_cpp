
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <algorithm>
#include <string>

Intern::Intern()
{
	if (DISP_DEBUG == 1)
		std::cout << "Intern constructor" << std::endl;
}

Intern::Intern(const Intern &other)
{
	if (DISP_DEBUG == 1)
		std::cout << "Intern copy constructor" << std::endl;
	(void)other;
}

Intern::~Intern()
{
	if (DISP_DEBUG == 1)
		std::cout << "Intern destructor" << std::endl;

}

Intern &Intern::operator=(const Intern &other)
{
	if (DISP_DEBUG == 1)
		std::cout << "Intern Assignemnt" << std::endl;
	if (this != &other)
	{
		this->~Intern();
		new (this) Intern(other);
	}
	return (*this);
}

int getLevel(std::string type)
{
	const std::string	list[3][2] = {{"shrubbery", "creation"}, {"robot", "request"}, {"presidential", "pardon"}};
	
	for (int i=0; (size_t)i < type.length(); i++)
		type[i] = std::toupper(type[i]);

	for (int j=0; j < 3; j++)
	{
		if (type.find(list[j][0]) != std::string::npos &&
			type.find(list[j][1]) != std::string::npos)
			return (j);
	}
	return(-42);

}

AForm *Intern::makeForm(std::string name, std::string type)
{
	int k;

	k = getLevel(type);
	switch (k) {
		case 0:
			return (new ShrubberyCreationForm(name));
		case 1:
			return (new RobotomyRequestForm(name));
		case 2:
			return (new PresidentialPardonForm(name));
		default:
			throw Intern::ReadException();
	}
	return (NULL);
}

const char *Intern::ReadException::what(void) const throw()
{
	return (RED "Input not valid" RESET);
};

