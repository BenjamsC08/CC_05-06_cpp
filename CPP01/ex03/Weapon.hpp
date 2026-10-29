#ifndef __WEAPON__
#define __WEAPON__

#include <string>
#include <ostream>
#include <iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string name);
		Weapon(const Weapon &other);
		Weapon &operator=(const Weapon &other);
		~Weapon();

		const std::string &getType() const;
		void setType(std::string type);


	private:
		std::string type;
		
};

#endif
