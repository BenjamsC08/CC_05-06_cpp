#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	// using ClapTrap::ClapTrap;

	public:
		ScavTrap(std::string);
		ScavTrap(const ScavTrap &);
		ScavTrap &operator=(const ScavTrap &other);

		~ScavTrap();

		void attack(const std::string& target);
		void guardGate();

	
	private:
};
