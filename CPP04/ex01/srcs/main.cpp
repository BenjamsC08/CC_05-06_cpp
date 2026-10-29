# include "Dog.hpp"
# include "Cat.hpp"
#include "WrongCat.hpp"


int main_42()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << '\n';
	delete j;//should not create a leak
	delete i;
	return 0;
}

int my_main()
{
	const Animal* meta = new Animal();
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
	meta->makeSound();

	delete[] animals;
	delete meta;
	return 0;

}

int main()
{
	main_42();
	// my_main();
	// Cat c;
}
