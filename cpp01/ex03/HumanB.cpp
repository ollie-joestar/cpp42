#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL) {
	std::cout << this->name << " was created" << std::endl;
}

HumanB::~HumanB() {
	std::cout << this->name << " is destroyed" << std::endl;
}

void HumanB::attack() {
	if (this->weapon)
		std::cout << this->name << " attacks with their " 
			<< this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " tries to attack and realizes that they don't have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
	std::cout << this->name << " got a " << this->weapon->getType() << std::endl;
}
