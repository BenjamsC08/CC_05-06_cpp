
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &);
		Ice &operator=(const Ice &);
		~Ice();
		virtual AMateria* clone() const;
};
