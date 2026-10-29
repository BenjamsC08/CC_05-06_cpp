#ifndef __CLAPTRAP__
# define __CLAPTRAP__

#include <iostream>

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define ORANGE "\033[0;91m"
# define PURPLE "\033[0;95m"
# define DARK_ORANGE "\033[0;33m"
# define PINK "\033[0;95m"
# define TEAL "\033[0;96m"
# define GRAY "\033[0;90m"

class ClapTrap
{
	public:
		ClapTrap(std::string);
		ClapTrap(const ClapTrap &);
		ClapTrap &operator=(const ClapTrap &);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void noEnergy(void);
		void noHealth(void);

		void setName(std::string);
		void setHitPoint(unsigned int);
		void setEnergyPoint(unsigned int);
		void setAttackDamage(unsigned int);

		std::string	  getName(void) const ;
		unsigned int  getHitPoint(void) const ;
		unsigned int  getEnergyPoint(void) const ;
		unsigned int  getAttackDamage(void) const ;


	private:
		std::string	  _name;
		unsigned int  _hitPoint;
		unsigned int  _energyPoint;
		unsigned int  _attackDamage;
};

#endif
