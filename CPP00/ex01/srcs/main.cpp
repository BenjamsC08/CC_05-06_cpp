#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream> 
#include <string> 


int main()
{
	PhoneBook repertory;
	std::string str;

	while (42)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT) :"<< std::endl;
		std::getline(std::cin, str);
		if (str != "ADD" && str != "SEARCH" && str != "EXIT")
			continue ;
		if (str == "ADD")
			repertory.AddContact();
		if (str == "SEARCH")
		{
			repertory.PrintContacts();
			std::cout << "Index :"<< std::endl;
			std::getline(std::cin, str);
			if (str.empty())
				continue ;
			int index = std::atoi(str.c_str());
			if (index < 1 || index > repertory.getNbContacts())
				continue ;
			else
				repertory.getContact(index).printContact();
		}
		if (str == "EXIT")
			break ;
	}
}
