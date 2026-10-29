
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

		virtual void  makeSound() const = 0;
		virtual std::string getType() const = 0;
		void setType(std::string type);
	protected:
		std::string _type;
};
