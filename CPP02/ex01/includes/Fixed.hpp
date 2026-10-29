#ifndef __FIXED__
# define __FIXED__

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed &);
		~Fixed();

		int	  getRawBits(void) const;
		void  setRawBits(int const raw);
		float toFloat(void) const;
		int	  toInt(void) const;


	private:
		int				  _value;
		const static int  _stash = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixPoint);



std::cout << "machin" << FIXED << "\n";

#endif
