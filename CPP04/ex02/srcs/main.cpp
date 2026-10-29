# include "Dog.hpp"
# include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	Animal** animals = new Animal*[20];

	for (int i=0; i < 20; i++)
	{
		if (i < 10)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();

	}
	for (int i=0; i < 20; i++)
	{

		std::cout << "Animals i:" << i << " is a "
			<< animals[i]->getType() << " :";
		animals[i]->makeSound();
	}
	for (int i=0; i < 20; i++)
	{
		delete animals[i];
	}
	// meta->makeSound();

	delete[] animals;
	// delete meta;
	return 0;
}
