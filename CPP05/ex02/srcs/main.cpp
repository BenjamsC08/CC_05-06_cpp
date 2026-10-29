#include "Bureaucrat.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

int main()
{

	std::cout << "\t\tShrubberyCreationForm\n" << std::endl;
	try {
		Bureaucrat a("Bob", 150);
		std::cout << a << std::endl;

		ShrubberyCreationForm shares("shares");

		a.signForm(shares);
		a.promote(145);

		std::cout << a << std::endl;
		std::cout << shares << std::endl;

		a.signForm(shares);
		a.executeForm(shares);

		a.promote(137);
		a.executeForm(shares);

	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\t\tRobotomyRequestForm\n" << std::endl;
	try {
		Bureaucrat a("Karim", 73);
		std::cout << a << std::endl;

		RobotomyRequestForm automaton("KariBot");
		std::cout << automaton << std::endl;
		a.signForm(automaton);
		a.promote();
		a.signForm(automaton);
		a.promote(45);
		a.executeForm(automaton);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\t\tPresidentialPardonForm\n" << std::endl;
	try {
		Bureaucrat a("Ibrahima", 12);
		std::cout << a << std::endl;

		PresidentialPardonForm bossPls("please");

		std::cout << bossPls << std::endl;

		a.signForm(bossPls);
		a.executeForm(bossPls);

		a.promote(2);
		a.executeForm(bossPls);

	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\t\tPresidentialPardonForm\n" << std::endl;
	try {
		Bureaucrat a("Ibrahima", 1);
		std::cout << a << std::endl;

		PresidentialPardonForm bossPls("please");

		std::cout << bossPls << std::endl;

		a.executeForm(bossPls);

		a.signForm(bossPls);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


}
