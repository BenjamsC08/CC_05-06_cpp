#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	if (DISP_DEBUG > 1)
	{
		std::cout << GREEN << "Construct Cure";
		std::cout << RESET << std::endl;
	}
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	this->_type = other._type;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Cure::~Cure()
{
	if (DISP_DEBUG > 1)
	{
		std::cout << GREEN << "Destruct Cure";
		std::cout << RESET << std::endl;
	}
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

