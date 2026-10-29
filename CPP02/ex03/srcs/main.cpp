#include "bsp.hpp"

void	disp(bool k, int i)
{
	if (k)
		std::cout << GREEN <<"this one is inside." << CYAN << "(look at assets/triangle" << i << ".png)" << RESET <<std::endl << std::endl;
	else
		std::cout << RED <<"this one is not inside." << CYAN << "(look at assets/triangle" << i << ".png)" << RESET << std::endl << std::endl;
}

int main( void ) {
	int i = 1;
	bool k;

	Point const a1(9.29, 4.88);
	Point const b1(-9.4, 9.66);
	Point const c1(-2.13, -2.47);
	Point const p1(-0.82, 1.16);
	std::cout << "a1: " << PINK << a1  << RESET << std::endl;
	std::cout << "b1: " << PINK << b1 << RESET << std::endl;
	std::cout << "c1: " << PINK << c1 << RESET << std::endl;
	std::cout << "p1: " << PINK << p1 << RESET << std::endl;
	k = bsp(a1, b1, c1, p1);
	disp(k, i++);

	Point const a2(4.0, 4.38);
	Point const b2(1.18, -4.5);
	Point const c2(-1.79, 7.65);
	Point const p2(2.35, 4.45);
	std::cout << "a2: " << PINK << a2  << RESET << std::endl;
	std::cout << "b2: " << PINK << b2 << RESET << std::endl;
	std::cout << "c2: " << PINK << c2 << RESET << std::endl;
	std::cout << "p2: " << PINK << p2 << RESET << std::endl;
	k = bsp(a2, b2, c2, p2);
	disp(k, i++);

	Point const a3(9.28,4.88);
	Point const b3(-9.4,9.66);
	Point const c3(10.45, -2.23);
	Point const p3(7.18,4.02);
	std::cout << "a3: " << PINK << a3  << RESET << std::endl;
	std::cout << "b3: " << PINK << b3 << RESET << std::endl;
	std::cout << "c3: " << PINK << c3 << RESET << std::endl;
	std::cout << "p3: " << PINK << p3 << RESET << std::endl;
	k = bsp(a3, b3, c3, p3);
	disp(k, i++);
	// outside
	Point const a4(9.28,4.88);
	Point const b4(-9.4,9.66);
	Point const c4(-2.13,-2.47);
	Point const p4(3.44,-2.46);
	std::cout << "a4: " << PINK << a4  << RESET << std::endl;
	std::cout << "b4: " << PINK << b4 << RESET << std::endl;
	std::cout << "c4: " << PINK << c4 << RESET << std::endl;
	std::cout << "p4: " << PINK << p4 << RESET << std::endl;
	k = bsp(a4, b4, c4, p4);
	disp(k, i++);
	// vertex A
	Point const a5(4,4.38);
	Point const b5(1.18,-4.5);
	Point const c5(-1.79,7.65);
	Point p5(44,4.58);
	p5 = a5;
	std::cout << "a5: " << PINK << a5  << RESET << std::endl;
	std::cout << "b5: " << PINK << b5 << RESET << std::endl;
	std::cout << "c5: " << PINK << c5 << RESET << std::endl;
	std::cout << "p5: " << PINK << p5 << RESET << std::endl;
	k = bsp(a5, b5, c5, p5);
	disp(k, i++);
	// edge AB
	Point const a6(8.46,1.58);
	Point const b6(5.73,0.8);
	Point const c6(-7.32,3.16);
	Point const p6(7.09,1.19);
	std::cout << "a6: " << PINK << a6  << RESET << std::endl;
	std::cout << "b6: " << PINK << b6 << RESET << std::endl;
	std::cout << "c6: " << PINK << c6 << RESET << std::endl;
	std::cout << "p6: " << PINK << p6 << RESET << std::endl;
	k = bsp(a6, b6, c6, p6);
	disp(k, i++);



	return 0;
}
