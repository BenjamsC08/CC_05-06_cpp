
#include <stdint.h>
#include "def.hpp"

class Serializer
{
	private:
		Serializer() {};
		Serializer(const Serializer &) {};
		~Serializer() {};
	    Serializer &operator=(const Serializer &) {return *this;};

	public:
		static uintptr_t serialize(Data *ptr)
		{
			return (reinterpret_cast<uintptr_t>(ptr));
		};
		static Data *deserialize(uintptr_t raw)
		{
			return (reinterpret_cast<Data *>(raw));
		};
};
