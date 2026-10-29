#include "AMateria.hpp"

class FireBall : public AMateria
{
	public:
		FireBall();
		FireBall(const FireBall &);
		FireBall &operator=(const FireBall &);
		~FireBall();
		virtual AMateria* clone() const;
};
