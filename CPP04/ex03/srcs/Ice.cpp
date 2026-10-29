#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	if (DISP_DEBUG > 1)
	{
		std::cout << BLUE << "Construct Ice";
		std::cout << RESET << std::endl;
	}
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	this->_type = other._type;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Ice::~Ice()
{
	if (DISP_DEBUG > 1)
	{
		std::cout << BLUE << "Destruct Ice";
		std::cout << RESET << std::endl;
	}
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

