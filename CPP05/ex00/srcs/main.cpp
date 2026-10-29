#include "Bureaucrat.hpp"
#include <exception>

int main()
{
	try {
		Bureaucrat a("BOB", 1222);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat a("BOB", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	try {
		Bureaucrat a("BOB", 150);
		std::cout << a << std::endl;
		a.promote();
		std::cout << a << std::endl;
		a.demote();
		std::cout << a << std::endl;
		a.demote();
		std::cout << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat a("Karim", 1);
		std::cout << a << std::endl;
		a.demote();
		std::cout << a << std::endl;
		a.promote();
		std::cout << a << std::endl;
		a.promote();
		std::cout << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}
