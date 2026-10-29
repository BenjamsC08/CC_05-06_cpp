# ifndef __POINT__
# define __POINT__

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float, const float);
		Point(const Point &);
		Point &operator=(const Point &);
		~Point();

		float	getPoint(char) const;
	

	private:
		const Fixed _x;
		const Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::ostream& operator<<(std::ostream &out, const Point &point);
#endif
