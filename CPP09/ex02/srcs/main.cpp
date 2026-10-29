
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "ListIdx.hpp"
#include "ListSort.hpp"
#include "def.hpp"

int usage(char *name)
{
	std::cerr << "ex: " << name << " 12 18 42 99 41\n";
	return (1);
}

std::string	cstring_tab_to_string(char **e, int size)
{
	std::string out;
	std::string nl;
	for (int i=0; i < size; i ++)
	{
		std::string tmp = e[i];
		if (tmp.find_first_not_of("0123456789") != std::string::npos)
			return (nl);
		out += e[i];
		if (i != size - 1)
			out += " ";
	}
	return (out);
}

template <typename ContainerT>
void p(const ContainerT &c)
{
	for (size_t i=0; i < c.size(); i++)
		std::cout << c[i] << ' ';
}


int main(int ac, char **av)
{
	if (ac < 2)
		return (usage(av[0]));
	try
	{
		std::string str = cstring_tab_to_string(av + 1, ac - 1);

		if (str.empty())
			return (usage(av[0]));

		std::vector<int> tab;
		ListIdx<int> tab0;
		double vecTime;
		double listTime;
		
		/*		Vector		*/

		clock_t start = clock();
		extractNumber<std::vector<int> >(str, tab);
		sortVec(tab);
		clock_t end = clock();
		vecTime = static_cast<double>((end - start) * 1000000.0) / CLOCKS_PER_SEC;

		/*		List		*/

		start = clock();
		extractNumber<ListIdx<int> >(str, tab0);
		sortList(tab0);
		end = clock();
		listTime = static_cast<double>((end - start) * 1000000.0) / CLOCKS_PER_SEC;

		/*		Display		  */

		std::cout << RED << "Before: " << str << RESET << '\n';
		std::cout << GREEN << "After:  "; p(tab); std::cout << RESET << '\n';


		std::cout << "Time to process a range of " << ac - 1;
		std::cout << " elements with `" << YELLOW << "std::vector" << RESET;
		std::cout << "`: " << vecTime << "us\n";

		// std::cout << RED << "Before: " << str << RESET << '\n';
		// std::cout << GREEN << "After:  "; p(tab0); std::cout << RESET << '\n';
		std::cout << "Time to process a range of " << ac - 1;
		std::cout << " elements with `" << YELLOW << "std::list" << RESET;
		std::cout << "`: " << listTime << "us\n";

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
}
