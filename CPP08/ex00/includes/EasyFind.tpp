#include <algorithm>
#include <iterator>
#include <sstream>

#include "def.hpp"

template <typename T>
void easyFind(T &container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		std::stringstream s;
		s << '`'<< value << "' not find";
		throw std::out_of_range(s.str());
	}
	std::cout << *it << " found at: " << std::distance(container.begin(), it);
	std::cout << '\n';
}
