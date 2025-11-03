#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Nameless_ScavTrap"), guarding(0) {
	hitPoints = ScavTrap::defaultHitPoints;
	energyPoints = ScavTrap::defaultEnergyPoints;
	attackDamage = ScavTrap::defaultAttackDamage;
	maxHP = ScavTrap::defaultHitPoints;
	std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), guarding(0) {
	hitPoints = ScavTrap::defaultHitPoints;
	energyPoints = ScavTrap::defaultEnergyPoints;
	attackDamage = ScavTrap::defaultAttackDamage;
	maxHP = ScavTrap::defaultHitPoints;
	std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) , guarding(other.guarding) {
	std::cout << "ScavTrap " << name << " copied." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << name << " assigned." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destructed." << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ScavTrap " << name << " shoots " << target 
				  << " , causing " << attackDamage << " points of damage!" << std::endl;
	} else if (hitPoints <= 0) {
		std::cout << "ScavTrap " << name << " cannot shoot due to being dead." << std::endl;
	} else {
		std::cout << "ScavTrap " << name << " cannot shoot due to lack of energy." << std::endl;
	}
}

void	ScavTrap::guardGate() {
	if (hitPoints <= 0) {
		std::cout << "ScavTrap " << name << " cannot enter Gate keeper mode due to being dead." << std::endl;
		return;
	}
	if (guarding) {
		std::cout << "ScavTrap " << name << " is already in Gate keeper mode." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
	guarding = 1;
}
