# include "bsp.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->~Point();
		new(this) Point(other); //placement new (not memory allocation)
	}
	return (*this);
}

Point::~Point()
{
}

float	Point::getPoint(char type) const
{
	if (type == 'x')
		return(_x.toFloat());
	else
		return(_y.toFloat());
}


float calc(float ax, float ay, float bx, float by, float px, float py)
{
	return ((ax - px)*(by - py) - (ay - py)*(bx - px));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float px = point.getPoint('x');
	float py = point.getPoint('y');

	float ax = a.getPoint('x');
	float ay = a.getPoint('y');
	float bx = b.getPoint('x');
	float by = b.getPoint('y');
	float cx = c.getPoint('x');
	float cy = c.getPoint('y');

	float e1 = roundf(calc(cx, cy, ax, ay, px, py));
	float e2 = roundf(calc(ax, ay, bx, by, px, py));
	float e3 = roundf(calc(bx, by, cx, cy, px, py));
	
	std::cout << "|e1:" << PINK << e1 << RESET << "| e2:" << PINK << e2 << RESET << "| e3:" << PINK << e3 << RESET << "|" << std::endl;

	if ((e1 > 0 && e2 > 0 && e3 > 0)  || (e1 < 0 && e2 < 0 && e3 < 0))
		return (true);
	else 
		return (false);
}

std::ostream& operator<<(std::ostream &out, const Point &point)
{
	out << "x: " << point.getPoint('x') << ", y: " << point.getPoint('y');
	return (out);
}
