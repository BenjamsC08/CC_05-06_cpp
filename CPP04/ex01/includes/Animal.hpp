
#pragma once

#include <iostream>
# include "def.hpp"

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &);
		Animal &operator=(const Animal &);
		virtual ~Animal();

		void  makeSound() const;
		std::string getType() const;
		void setType(std::string type);
	protected:
		std::string _type;
};
