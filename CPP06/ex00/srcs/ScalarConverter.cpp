#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <ostream>
#include <limits.h>
#include <limits>
#include <float.h>
#include <string>

# define MINF  -1
# define PINF   1
# define NN     0
# define UKNOWN 2

int findValue(std::string value)
{
	if (value == "-inf") return MINF;
	if (value == "-inff") return MINF;
	if (value == "+inf") return PINF;
	if (value == "+inff") return PINF;
	if (value == "nan") return NN;
	if (value == "nanf") return NN;
	return UKNOWN;
}

void charCase(char c)
{
	if (c >= 32  && c < 127)
		std::cout << "char : '" << static_cast<char>(c) << "'" << std::endl;
	else if (c < 32 || c == 127)
		std::cout << "char : Unprintable" << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
}

void  intCase(int nb, double pv)
{
	if (nb >= 32  && nb < 127)
		std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
	else if (nb < 32 || nb == 127)
		std::cout << "char : Unprintable" << std::endl;
	else
		std::cout << "char : Impossible" << std::endl;
	std::cout << "int : " << nb << std::endl;
	if (pv == 0)
		std::cout << "float : " << static_cast<float>(nb) << ".0f" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(nb) << "f" << std::endl;
	if (pv == 0)
		std::cout << "double : " << static_cast<double>(nb) << ".0" << std::endl;
	else
		std::cout << "double : " << static_cast<double>(nb) << std::endl;
}

void floatCase(float nb, double pv)
{
	long nbl = static_cast<long>(nb);
	
	if (nb >= 32  && nb < 127)
		std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
	else if (nb < 32 || nb == 127)
		std::cout << "char : Unprintable" << std::endl;
	else
		std::cout << "char : Impossible" << std::endl;
	if (nbl >= INT_MIN && nbl <= INT_MAX)
		std::cout << "int : " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int : Impossible" << std::endl;
	if (pv == 0)
		std::cout << "float : " << nb << ".0f" << std::endl;
	else
		std::cout << "float : " << nb << "f" << std::endl;
	if (pv == 0)
		std::cout << "double : " << static_cast<double>(nb) << ".0" << std::endl;
	else
		std::cout << "double : " << static_cast<double>(nb) << std::endl;
}

void doubleCase(double nb, double pv)
{
	long nbl = static_cast<long>(nb);

	if (nb >= 32  && nb < 127)
		std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
	else if (nb < 32 || nb == 127)
		std::cout << "char : Unprintable" << std::endl;
	else
		std::cout << "char : Impossible" << std::endl;
	if (nbl >= INT_MIN && nbl <= INT_MAX)
		std::cout << "int : " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int : Impossible" << std::endl;
	if ((nb >= -std::numeric_limits<float>::max() && nb <= std::numeric_limits<float>::max()))
		if (pv == 0)
			std::cout << "float : " << static_cast<float>(nb) << ".0f" << std::endl;
		else
			std::cout << "float : " << static_cast<float>(nb) << "f" << std::endl;
	else
		std::cout << "float : Impossible" << std::endl;
	if (pv == 0)
		std::cout << "double : " << nb << ".0" << std::endl;
	else
		std::cout << "double : " << nb << std::endl;
}

void ScalarConverter::convert(std::string value)
{

	switch (findValue(value))
	{
		case NN:
			std::cout << "char : Impossible" << std::endl;
			std::cout << "int : Impossible" << std::endl;
			std::cout << "float : nanf" << std::endl;
			std::cout << "double : nan" << std::endl;
			return ;
		case MINF:
			std::cout << "char : Impossible" << std::endl;
			std::cout << "int : Impossible" << std::endl;
			std::cout << "float : -inff" << std::endl;
			std::cout << "double : -inf" << std::endl;
			return ;
		case PINF:
			std::cout << "char : Impossible" << std::endl;
			std::cout << "int : Impossible" << std::endl;
			std::cout << "float : +inff" << std::endl;
			std::cout << "double : +inf" << std::endl;
			return ;
	}

	const char *str = value.c_str();
	double n = std::atof(str);
	double k, m;
	m = std::modf(n, &k);

	if (n > 1000000 || n < -1000000)
		m = 42;
	if (n == INFINITY)
	{
		std::cout << "char : Impossible" << std::endl;
		std::cout << "int : Impossible" << std::endl;
		if (value.find('-'))
		{
			std::cout << "float : -inff" << std::endl;
			std::cout << "double : -inf" << std::endl;
		}
		else
		{
			std::cout << "float : +inff" << std::endl;
			std::cout << "double : +inf" << std::endl;
		}
	}
	if (value.find('f') != std::string::npos
		&& n <= -std::numeric_limits<float>::max() 
		&& n >= std::numeric_limits<float>::min())
		floatCase(n, m);
	else if (value.find('.')  != std::string::npos || n > INT_MAX || n < INT_MIN)
		doubleCase(n, m);
	else if (value.length() == 1 && (*str < '0' || *str > '9'))
		charCase(*str);
	else if (n <= INT_MAX)
		intCase(n, m);
	else
		std::cout << "can't convert that" << std::endl;

}
