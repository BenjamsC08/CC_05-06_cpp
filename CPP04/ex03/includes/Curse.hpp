#include "AMateria.hpp"

class Curse : public AMateria
{
	public:
		Curse();
		Curse(const Curse &);
		Curse &operator=(const Curse &);
		~Curse();
		virtual AMateria* clone() const;
};
