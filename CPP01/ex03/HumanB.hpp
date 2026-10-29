#ifndef __HUMANB__
#define __HUMANB__

#include <string>
#include <ostream>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string);
		HumanB(const HumanB &other);
		HumanB &operator=(const HumanB &other);
		~HumanB();

		void attack() const;
		void setWeapon(Weapon &tool);


	private:
		std::string name;
		Weapon *tool = NULL;
		
};

#endif
