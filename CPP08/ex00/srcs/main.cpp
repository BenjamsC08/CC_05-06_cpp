
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "EasyFind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(2);
	v.push_back(11);

	try {
		easyFind(v, 12);
	}
	catch (std::exception &e) {
		std::cerr << "vector :" << e.what() << '\n';
	}

	std::list<int> l;
	l.push_back(22);
	l.push_back(8);
	l.push_back(5);
	l.push_back(12);

	try {
		easyFind(l, 5);
	}
	catch (std::exception &e) {
		std::cerr <<  "list :" <<e.what() << '\n';
	}

	std::deque<int> d;
	d.push_back(7);
	d.push_back(12);
	d.push_back(24);
	d.push_back(7);

	try {
		easyFind(d, 7);
	}
	catch (std::exception &e) {
		std::cerr <<  "deque :" <<e.what() << '\n';
	}

	return (0);
}
