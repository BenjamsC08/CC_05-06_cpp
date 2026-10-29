#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <map>
#include <cstring>
#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

void	print_map(std::map<long, float> &m)
{
	std::map<long,float>::iterator it = m.begin();
	std::cout << "mymap contains:\n";
	for (it=m.begin(); it!=m.end(); ++it)
		std::cout << it->first << " => " << it->second << "$\n";
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << av[0] << " <input_file>\n", 1);

	try
	{
		std::string pathIn(av[1], strlen(av[1]));
		BitcoinExchange btc(pathIn);
		btc.exec_file();
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << '\n';
	}
}
