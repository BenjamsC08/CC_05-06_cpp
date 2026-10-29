#ifndef __CLAPTRAP__
# define __CLAPTRAP__

#include <iostream>

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PINK "\033[0;95m"

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

	private:
		std::string	  _name;
		unsigned int  _hitPoint;
		unsigned int  _energyPoint;
		unsigned int  _attackDamge;
};

#endif
