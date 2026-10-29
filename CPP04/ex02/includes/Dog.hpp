#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal, protected Brain
{
	public:
		Dog();
		Dog(const Dog &);
		Dog &operator=(const Dog &);
		~Dog();

		void  makeSound() const;
		std::string getType() const;

	private:
		Brain *_brain;

};
