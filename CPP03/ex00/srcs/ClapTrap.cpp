#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamge(0)
{
		std::cout << "construct ClapTrap `" << this->_name << "`" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	_name(other._name), _hitPoint(other._hitPoint), _energyPoint(other._energyPoint), _attackDamge(other._attackDamge)
{}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->~ClapTrap();
		new (this) ClapTrap(other);
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "destruct ClapTrap `" << this->_name << "`" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->_hitPoint)
		this->noHealth();
	else if (!this->_energyPoint)
		this->noEnergy();
	else
	{
		std::cout << GREEN << "ClapTrap `" << this->_name << "` attack " << target << ", causing ";
		std::cout << _attackDamge << " points of damage !";
		std::cout << YELLOW << " (energy point left: " << --this->_energyPoint << ")" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint < amount)
		this->_hitPoint = 0;
	else
		this->_hitPoint -= amount;
	std::cout << RED << "ClapTrap `" << this->_name << "` take " << amount << " points of damage !";
	std::cout << YELLOW << " (hit point left: " << this->_hitPoint << ")" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_hitPoint)
		this->noHealth();
	else if (!this->_energyPoint)
		this->noEnergy();
	else 
	{
		std::cout << BLUE << "ClapTrap `" << this->_name << "` regained " << amount << " points of life !";
		std::cout << YELLOW << " (energy point left: " << --this->_energyPoint << ") (hp: ";
		std::cout << this->_hitPoint << " -> " << this->_hitPoint + amount << ")" RESET << std::endl;
		this->_hitPoint += amount;
	}
}

void ClapTrap::noEnergy()
{
	std::cout << PINK << "ClapTrap `" << this->_name << "` has no more energy !" << RESET << std::endl;

}

void ClapTrap::noHealth()
{
	std::cout << PINK << "ClapTrap `" << this->_name << "` has no more Health (hit point) !" << RESET << std::endl;
}
