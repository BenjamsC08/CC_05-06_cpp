#include <string>
#include <ostream>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr_str = &str;
	std::string &ref_str = str;

	std::cout << "addr str : \t\t" << &str << std::endl;
	std::cout << "ptr_str : \t\t" << ptr_str << std::endl;
	std::cout << "addr ref str: \t\t" << &ref_str << std::endl;

	std::cout << "str : \t\t\t" << str << std::endl;
	std::cout << "pointed by ptr_str : \t" << *ptr_str << std::endl;
	std::cout << "ref to str : \t\t" << ref_str << std::endl;
}
