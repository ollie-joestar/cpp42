#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

int	main()
{
	std::cout << GREEN << "----- Mandatory subject tests -----" << RESET << std::endl;
	const AAnimal *array[6];
	for (int i = 0; i < 6; i++)
		if (i % 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	for (int i = 0; i < 6; i++) {
		std::cout << "Index " << i << ": " << array[i]->getType() << std::endl;
		array[i]->makeSound();
	}
	for (int i = 0; i < 6; i++)
		delete array[i];
	
	// Uncommenting the following lines to show that AAnimal cannot be instantiated
	// const AAnimal* creature = new AAnimal();
	// creature->makeSound();
	// delete creature;

	std::cout << GREEN << "\n----- Testing AAnimals -----" << RESET << std::endl;
	const AAnimal* basic_dog = new Dog();
	const AAnimal* basic_cat = new Cat();
	std::cout << basic_dog->getType() << std::endl;
	basic_dog->makeSound();
	std::cout << basic_cat->getType() << std::endl;
	basic_cat->makeSound();

	delete basic_dog;
	delete basic_cat;

	std::cout << GREEN << "\n----- Testing Dog Brains -----" << RESET << std::endl;
	const Dog* dog1 = new Dog();
	dog1->getBrain()->setIdea(0, "Chasing cats");
	const Dog* dog2 = new Dog(*dog1);
	std::cout << "Dog1 Idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 Idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;
	dog2->getBrain()->setIdea(0, "Playing fetch");
	std::cout << "After modifying Dog2's idea" << std::endl;
	std::cout << "Dog1 Idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 Idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;

	delete dog1;
	delete dog2;

	std::cout << GREEN << "\n----- Testing Cat Brains -----" << RESET << std::endl;
	const Cat* cat1 = new Cat();
	cat1->getBrain()->setIdea(0, "Climbing trees");
	const Cat* cat2 = new Cat(*cat1);
	std::cout << "Cat1 Idea[0]: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 Idea[0]: " << cat2->getBrain()->getIdea(0) << std::endl;
	cat2->getBrain()->setIdea(0, "Chasing mice");
	std::cout << "After modifying Cat2's idea" << std::endl;
	std::cout << "Cat1 Idea[0]: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 Idea[0]: " << cat2->getBrain()->getIdea(0) << std::endl;

	delete cat1;
	delete cat2;

	return 0;
}
