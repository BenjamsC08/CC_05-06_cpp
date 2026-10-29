#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "creation de " << name << std::endl;
}

Zombie::Zombie(const Zombie &other) : name(other.name)
{}
		
Zombie &Zombie::operator=(const Zombie &other)
{
	name = other.name;
	return (*this);
}

Zombie::~Zombie()
{
	std::cout << "destruct zombie :" << this->name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void  Zombie::setNameZombie(std::string name)
{
	this->name = name;
}

const std::string &Zombie::getNameZombie(std::string name) const
{
	return (this->name);
}

