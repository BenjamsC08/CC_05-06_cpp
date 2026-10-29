#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Constructor Cat" << std::endl;
	this->setType("Cat");
}

Cat::Cat(const Cat &other)
{
	this->setType(other.getType());
}

Cat	  &Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor Cat" << std::endl;
}
