
#include "def.hpp"
#include <ctime>
#include <cstdlib>

template <typename T> class Array
{
	public:
		Array();
		Array(t_uint size);
		Array(const Array &other);
		~Array();

		Array &operator=(const Array &other);
		T &operator[](const t_uint n);
		t_uint size();

	private:
		t_uint	_size;
		T		*_array;

};

#include "Array.tpp"
