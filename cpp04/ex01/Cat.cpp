#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		Brain* tempBrain = new Brain(*(other.brain));
		delete this->brain;
		this->brain = tempBrain;
	}
	return *this;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}
