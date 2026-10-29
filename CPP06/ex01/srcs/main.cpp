#include "Serializer.hpp"
#include <iterator>
#include <ostream>
#include <string>

int main()
{
	std::cout << "Initialisation:" << std::endl;
	Data machin = {4, "truc"};
	std::cout << "id: " << machin.id << ", name: " << machin.name << std::endl << std::endl;

	std::cout << "Serialisation:" << std::endl;
	uintptr_t add = Serializer::serialize(&machin);
	std::cout << "add: " << add << std ::endl << std::endl;

	std::cout << "Deserialisation:" << std::endl;
	Data *truc = Serializer::deserialize(add);
	std::cout << "id: " << truc->id << ", name: " << truc->name << std::endl << std::endl;

	std::cout << "Verification:" << std::endl;
	std::string same = (truc == &machin) ? "oui" : "non";
	std::cout << "truc == &machin : " << same  << std::endl;
}
