#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("nameless_diamond_trap_clap_name"), name("nameless_diamond_trap") {
	this->hitPoints = FragTrap::defaultHitPoints;
	this->energyPoints = ScavTrap::defaultEnergyPoints;
	this->attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "DiamondTrap " << this->name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), name(name) {
	this->hitPoints = FragTrap::defaultHitPoints;
	this->energyPoints = ScavTrap::defaultEnergyPoints;
	this->attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "DiamondTrap " << this->name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	std::cout << "DiamondTrap " << this->name << " copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	std::cout << "DiamondTrap " << this->name << " assigned." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destructed." << std::endl;
}

void DiamondTrap::whoAmI() {
	if (this->hitPoints == 0) {
		std::cout << "DiamondTrap " << this->name << " has no hit points left and cannot identify itself." << std::endl;
		return;
	}
	std::cout << "I'm announcing that my DiamondTrap name is - " << this->name << ", but my official ClapTrap name is - " << ClapTrap::name << std::endl;
}

unsigned int DiamondTrap::getHitPoints() const {
	return this->hitPoints;
}

unsigned int DiamondTrap::getEnergyPoints() const {
	return this->energyPoints;
}

unsigned int DiamondTrap::getAttackDamage() const {
	return this->attackDamage;
}

std::string DiamondTrap::getName() const {
	return this->name;
}
