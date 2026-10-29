#include <iostream>

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << av[0] << "\" {expression} \"\n";
		return 0;
	}

	try
	{
		RPN::calculate(av[1]);
	} 
	catch (RPN::BadExpressionException &err)
	{
		std::cerr << err.what() << '\n';
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << '\n';
	}
	catch ( ... )
	{
		std::cerr << "Something Wrong\n";
	}

}
