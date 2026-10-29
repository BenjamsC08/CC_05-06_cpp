#pragma once

#include "def.hpp"
#include <iostream>

class ScalarConverter
{
	protected:
		ScalarConverter() {};
		ScalarConverter(const ScalarConverter &) {};
		~ScalarConverter() {};
		ScalarConverter &operator=(const ScalarConverter &) {return *this;};
	public:
		static void convert(std::string);
};
