#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Constructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): _type(other._type)
{

}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	if (this->_type == "WrongCat")
		std::cout << "VROUUUM" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}
