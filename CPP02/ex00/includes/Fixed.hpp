#ifndef __FIXED__
# define __FIXED__

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed &);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int value;
		const static int stash = 8;
};


#endif
