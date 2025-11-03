#include "Weapon.hpp"

Weapon::Weapon() {
	this->type = "Typeless Weapon";
	std::cout << this->type << " was created" << std::endl;
}

Weapon::Weapon(std::string type) {
	this->type = type;
	std::cout << this->type << " was created" << std::endl;
}

Weapon::~Weapon() {
	std::cout << this->type << " is destroyed" << std::endl;
}

void	Weapon::setType(std::string type) {
	this->type = type;
}

const std::string& Weapon::getType() const {
	return this->type;
}
