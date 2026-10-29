#ifndef __HUMANA__
#define __HUMANA__

#include <string>
#include <ostream>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string, Weapon &tool);
		HumanA(const HumanA &other);
		HumanA &operator=(const HumanA &other);
		~HumanA();

		void attack() const;


	private:
		std::string name;
		Weapon &tool;
		
};

#endif
