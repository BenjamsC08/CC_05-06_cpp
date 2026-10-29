# include "Dog.hpp"
# include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* y = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << y->getType() << " " << std::endl;
	y->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	delete y;
	return 0;
}
