#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name + "_clap_name")
{
	this->_name = name;
	std::cout << "construct Diamond Trap `" << this->getName() << "`" << std::endl;
	this->FragTrap::setHitPoint(this->FragTrap::getHitPoint());
	this->ScavTrap::setEnergyPoint(this->ScavTrap::getEnergyPoint());
	this->FragTrap::setAttackDamage(this->FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
	ClapTrap(other.getName() + "_clap_name"), ScavTrap(other.getName()), FragTrap(other.getName())
{
	this->_name = other.getName();
	this->FragTrap::setName(other.getName() + "_clap_name");
	this->FragTrap::setHitPoint(other.FragTrap::getHitPoint());
	this->ScavTrap::setEnergyPoint(other.ScavTrap::getEnergyPoint());
	this->FragTrap::setAttackDamage(other.FragTrap::getAttackDamage());
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->FragTrap::setHitPoint(other.FragTrap::getHitPoint());
		this->ScavTrap::setEnergyPoint(other.ScavTrap::getEnergyPoint());
		this->FragTrap::setAttackDamage(other.FragTrap::getAttackDamage());
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "destruct Diamond one" << std::endl;
}

const std::string DiamondTrap::getName(void) const
{
	return(this->_name);
}

void  DiamondTrap::whoAmI()
{
	std::cout << BLUE << "Claptrap name -> " << YELLOW << this->FragTrap::getName();
	std::cout << BLUE << " || DiamondTrap name -> " << YELLOW << this->getName() << RESET << std::endl;

}
