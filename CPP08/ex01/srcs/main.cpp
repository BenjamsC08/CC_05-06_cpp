#include <cstdlib>
#include <exception>
#include <iostream>

#include "def.hpp"
#include "Span.hpp"


int main()
{	
	/*
	 *
	 * Block 0
	 *
	 */
	std::cout << ORANGE << "BLOCK 1:\n" << RESET;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "the shortest distance is: " << sp.shortestSpan() << '\n';
		std::cout << "the longest distance is: " << sp.longestSpan() << '\n';
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	catch (...)
	{
		std::cerr << RED << "Something was thrown but not an exception\n";
		std::cerr << RESET;
	}

	/*
	 *
	 * Block 1
	 *
	 */
	std::cout << ORANGE << "BLOCK 1:\n" << RESET;
	try {
		Span sp = Span(5);
		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		std::cout << "the shortest distance is: " << sp.shortestSpan() << '\n';
		std::cout << "the longest distance is: " << sp.longestSpan() << '\n';
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	catch (...)
	{
		std::cerr << RED << "Something was thrown but not an exception\n";
		std::cerr << RESET;
	}

	/*
	 *
	 * Block 2
	 *
	 */

	std::cout << ORANGE << "BLOCK 2:\n" << RESET;
	try {

		Span sp(10000);
		sp.addNumber(0, 9, 2);
		std::cout << "the shortest distance is: " << sp.shortestSpan() << '\n';
		std::cout << "the longest distance is: " << sp.longestSpan() << '\n';
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';

	}
	catch (...)
	{
		std::cerr << RED << "Something was thrown but not an exception\n";
		std::cerr << RESET;
	}

	/*
	 *
	 * Block 3
	 *
	 */

	// std::cout << ORANGE << "BLOCK 3:\n" << RESET;
	// try {
	//
	// 	Span sp(45);
	// 	std::cout << YELLOW;
	// 	for (size_t i=0; i < 45; i++)
	// 	{
	// 		int nb = rand() % INT_MAX;
	// 		sp.addNumber(nb);
	// 		std::cout << "add `" << nb << "' to span\n";
	// 	}
	// 	std::cout << RESET;
	// 	std::cout << "the shortest distance is: " << sp.shortestSpan() << '\n';
	// 	std::cout << "the longest distance is: " << sp.longestSpan() << '\n';
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << RED << e.what() << RESET << '\n';
	//
	// }
	// catch (...)
	// {
	// 	std::cerr << RED << "Something was thrown but not an exception\n";
	// 	std::cerr << RESET;
	// }

	return (0);
}
