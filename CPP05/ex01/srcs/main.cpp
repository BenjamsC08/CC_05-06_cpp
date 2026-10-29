#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main()
{
	try
	{
		Form a ("Bad Form", 152, 12);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form a ("Bad Form", 2, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat a("Bob", 150);
		std::cout << a << std::endl;
		a.promote();
		std::cout << a << std::endl;
		Form shares("shares", 16, 1);
		std::cout << shares << std::endl;
		shares.beSigned(a);

	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat a("Karim", 16);
		std::cout << a << std::endl;
		Form shares("shares", 16, 1);
		std::cout << shares << std::endl;
		shares.beSigned(a);
		shares.execForm(a);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat a("Ibrahima", 1);
		std::cout << a << std::endl;
		Form shares("shares", 16, 1);
		std::cout << shares << std::endl;
		a.signForm(shares);
		shares.execForm(a);

	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


}
