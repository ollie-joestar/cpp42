#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

int	main()
{
	std::cout << GREEN << "----- Testing Animals -----" << RESET << std::endl;
	const Animal* creature = new Animal();
	const Animal* basic_dog = new Dog();
	const Animal* basic_cat = new Cat();
	std::cout << basic_dog->getType() << std::endl;
	basic_dog->makeSound();
	std::cout << basic_cat->getType() << std::endl;
	basic_cat->makeSound();
	std::cout << creature->getType() << std::endl;
	creature->makeSound();

	delete basic_cat;
	delete basic_dog;
	delete creature;

	std::cout << GREEN << "\n----- Testing Wrong Animals -----" << RESET << std::endl;
	const WrongAnimal* wrongCreature = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	std::cout << wrongCreature->getType() << std::endl;
	wrongCreature->makeSound();

	delete wrongCat;
	delete wrongCreature;
	std::cout << GREEN << "\n----- WrongCat memory test -----" << RESET << std::endl;
	WrongCat wc1;

	return 0;
}
