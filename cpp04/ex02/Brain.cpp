#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < brainPower; ++i) {
		ideas[i] = "Empty";
	}
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < brainPower; ++i) {
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < brainPower; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < brainPower) {
		ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < brainPower) {
		return ideas[index];
	}
	std::cout << "Index out of bounds. Returning empty idea" << std::endl;
	return "";
}
