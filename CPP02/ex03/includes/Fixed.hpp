#ifndef __FIXED__
# define __FIXED__

# include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed &);
		~Fixed();
		
		// overload constructor
		Fixed(const int);
		Fixed(const float);
		//accessors
		int	  getRawBits(void) const;
		void  setRawBits(int const raw);
		float toFloat(void) const;
		int	  toInt(void) const;
		//logic
		bool operator>(const Fixed &);
		bool operator<(const Fixed &);
		bool operator>=(const Fixed &);
		bool operator<=(const Fixed &);
		bool operator==(const Fixed &);
		bool operator!=(const Fixed &);
		//aritmetic
		float operator+(const Fixed &);
		float operator-(const Fixed &);
		float operator*(const Fixed &);
		float operator/(const Fixed &);
		// incr & decr
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
		// func
		static Fixed &min(Fixed &, Fixed &);
		static Fixed &max(Fixed &, Fixed &);
		static const Fixed &max(const Fixed &, const Fixed &);


	private:
		int				  _value;
		const static int  _stash = 8;
};

#endif
