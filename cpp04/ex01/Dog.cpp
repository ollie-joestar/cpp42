#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->type = other.type;
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		Brain* tempBrain = new Brain(*(other.brain));
		delete this->brain;
		this->brain = tempBrain;
	}
	return *this;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->brain;
}
