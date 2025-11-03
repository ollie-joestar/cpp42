#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Nameless_FragTrap") {
	hitPoints = FragTrap::defaultHitPoints;
	energyPoints = FragTrap::defaultEnergyPoints;
	attackDamage = FragTrap::defaultAttackDamage;
	maxHP = FragTrap::defaultHitPoints;
	std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	hitPoints = FragTrap::defaultHitPoints;
	energyPoints = FragTrap::defaultEnergyPoints;
	attackDamage = FragTrap::defaultAttackDamage;
	maxHP = FragTrap::defaultHitPoints;
	std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap " << name << " copied." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << name << " assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destructed." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (hitPoints <= 0) {
		std::cout << "FragTrap " << name << " cannot request high fives due to being dead." << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " requests high fives from everyone!" << std::endl;
}
