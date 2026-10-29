# include "Ice.hpp"
# include "Cure.hpp"
# include "Curse.hpp"
# include "FireBall.hpp"
# include "Character.hpp"
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"


int main_subject()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
}

int my_main()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria* tmp;
	tmp = src->createMateria("curse");
	delete tmp;
	src->learnMateria(new Curse());
	src->learnMateria(new FireBall());
	src->learnMateria(new Ice());

	ICharacter* s1 = new Character("Sorcer1");

	s1->equip(src->createMateria("ice"));
	s1->equip(src->createMateria("cure"));
	s1->equip(src->createMateria("cure"));
	s1->equip(src->createMateria("ice"));
	s1->equip(src->createMateria("ice"));

	s1->use("cure", *s1);
	s1->use("curse", *s1);
	s1->unequip(3);
	s1->unequip(2);
	s1->equip(src->createMateria("curse"));
	s1->use("curse", *s1);

	ICharacter* s2 = new Character("Sorcer2");
	s2->equip(src->createMateria("ice"));
	s2->equip(src->createMateria("cure"));

	s1->unequip(1);
	s1->unequip(2);
	s1->unequip(5);

	s2->use(1, *s1);
	s1->use(0, *s2);
	s1->use(42, *s2);

	s1->use("", *s1);


	ICharacter* s3 = new Character(*static_cast<Character*>(s1)); // permet de faire une copie profonde pcq en cpp98 passer de Character vers ICharcter est naturel mais pas l'inverse

	delete s1;

	s3->use(0, *s2);
	s3->equip(src->createMateria("ice"));
	s3->equip(src->createMateria("curse"));
	s3->equip(src->createMateria("fireball"));
	s3->equip(src->createMateria("ice"));

	s3->use("ice", *s2);
	s3->use("fireball", *s2);

	delete s2;
	delete s3;

	delete src;
	return (0);
}

int matisse_main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

int main()
{
	// std::cout << GRAY << "****************" << std::endl;
	// std::cout << "* Subject Main *" << std::endl;
	// std::cout << "****************" << RESET << std::endl;
	// std::cout << std::endl;
	// main_subject();
	// std::cout << std::endl << GRAY << "\t\t -------" << RESET << std::endl << std::endl;
	// std::cout << GRAY << "***********" << std::endl;
	// std::cout << "* My Main *" << std::endl;
	// std::cout << "***********" << RESET << std::endl;
	// std::cout << std::endl;
	// my_main();
	//
	//
	matisse_main();

}
