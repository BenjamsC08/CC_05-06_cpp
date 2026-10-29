
#pragma once

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &);
		WrongAnimal &operator=(const WrongAnimal &);
		~WrongAnimal();

		void  makeSound() const;
		std::string getType() const;
		void setType(std::string type);
	protected:
		std::string _type;
};
