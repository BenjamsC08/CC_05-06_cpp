#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	// ScalarConverter a = ScalarConverter();
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return (0);
	}
	else if (argc != 1)
		return (1);

	std::cout << TEAL << "./convert 12:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("12"));
	std::cout << TEAL << "./convert 48:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("48"));

	std::cout << std::endl << TEAL << "./convert 42.01f:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("42.01f"));

	std::cout << std::endl << TEAL << "./convert -42.2:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("-42.2"));

	std::cout << std::endl << TEAL << "./convert 0.00000001" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("0.00000001"));

	std::cout << std::endl << TEAL << "./convert nan:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("nan"));
	std::cout << std::endl << TEAL << "./convert nanf:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("nanf"));

	std::cout << std::endl << TEAL << "./convert +inff:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("+inff"));
	std::cout << std::endl << TEAL << "./convert -inff:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("-inff"));

	std::cout << std::endl << TEAL << "./convert -inf:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("-inf"));
	std::cout << std::endl << TEAL << "./convert +inf:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("+inf"));

	std::cout << std::endl << TEAL << "./convert 2147483649:" << RESET << std::endl;
	ScalarConverter::convert(static_cast<std::string>("2147483649"));

}

