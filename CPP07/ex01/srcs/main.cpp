
#include "Iter.hpp"

template <typename T>
void print(T &value)  {	std::cout << value << std::endl;  }

int main()
{
	{
		std::cout << GRAY << "// String\n" << RESET;
		std::string str = "machin";
		char *test = (char *)str.c_str();
		std::cout << CYAN << "string: `" << str << "` iter:\n" << RESET;
		iter (test, str.length(), print<char>);
		std::cout << '\n';
	}
	{
		std::cout << GRAY << "// String Tab\n" << RESET;
		std::string test[] = {"pepe", "test"};
		iter (test, 2, print<std::string>);
		std::cout << '\n';
		// iter (test, 2, print<const std::string>);
		// std::cout << '\n';
	}
	{
		std::cout << GRAY << "// Int tab\n" << RESET;
		int *ptr = new int[5];
		for (int i=0; i < 5; i++)
			ptr[i] = i + 1 * i * i;
		iter (ptr,5, print<int>);
		// std::cout << '\n';
		// iter (ptr, 5, print<const int>);
		delete[] ptr;
	}
}
