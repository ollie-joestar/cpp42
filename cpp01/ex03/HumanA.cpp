#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
	std::cout << this->name << " was created" << std::endl;
}

HumanA::~HumanA() {
	std::cout << this->name << " is destroyed" << std::endl;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
