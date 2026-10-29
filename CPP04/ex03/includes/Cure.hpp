#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &);
		Cure &operator=(const Cure &);
		~Cure();
		virtual AMateria* clone() const;
};

