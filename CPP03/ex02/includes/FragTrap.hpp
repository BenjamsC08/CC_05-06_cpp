#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{

	public:
		FragTrap(std::string);
		FragTrap(const FragTrap &);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys(void);

	
	private:
};
