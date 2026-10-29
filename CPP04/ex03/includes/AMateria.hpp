#pragma once

# include <iostream>
# include "def.hpp"

# define MAX_ITEMS 4

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const &);
		AMateria(const AMateria &);
		AMateria &operator=(const AMateria &);
		virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	void setType(std::string);
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
