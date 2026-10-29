#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string);
		DiamondTrap(const DiamondTrap &);
		DiamondTrap &operator=(const DiamondTrap &other);

		~DiamondTrap();

		using ScavTrap::attack;

		const std::string getName(void) const;
		void  whoAmI();

	private:
		std::string _name;
};
