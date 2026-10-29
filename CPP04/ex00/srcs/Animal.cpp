#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Constructor Animal" << std::endl;
}

Animal::Animal(std::string type)
{
	this->_type = type;
}

Animal::Animal(const Animal &other): _type(other._type)
{

}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor Animal" << std::endl;
}

void	Animal::makeSound() const
{
	if (this->_type == "Dog")
		std::cout << "Wouaff" << std::endl;
	if (this->_type == "Cat")
		std::cout << "Meaooow" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

