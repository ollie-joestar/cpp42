#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Nameless") {
	hitPoints = defaultHitPoints;
	energyPoints = defaultEnergyPoints;
	attackDamage = defaultAttackDamage;
	maxHP = defaultHitPoints;
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name) {
	hitPoints = defaultHitPoints;
	energyPoints = defaultEnergyPoints;
	attackDamage = defaultAttackDamage;
	maxHP = defaultHitPoints;
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage), maxHP(other.maxHP) {
	std::cout << "ClapTrap " << name << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		maxHP = other.maxHP;
	}
	std::cout << "ClapTrap " << name << " assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destructed." << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target 
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
	} else if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " cannot attack due to being dead." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " cannot attack due to lack of energy." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= amount) {
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " has taken " << amount 
				  << " points of damage and is now dead!" << std::endl;
	} else {
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " has taken " << amount 
				  << " points of damage, remaining hit points: " << hitPoints << "." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints == maxHP) {
		std::cout << "ClapTrap " << name << " is already at maximum hit points." << std::endl;
		return;
	}
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		hitPoints += amount;
		if (hitPoints > this->maxHP) {
			hitPoints = this->maxHP;
		}
		std::cout << "ClapTrap " << name << " repairs itself for " << amount 
				  << " points, new hit points: " << hitPoints << "." << std::endl;
	} else if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " cannot be repaired due to being dead." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " cannot be repaired due to lack of energy." << std::endl;
	}
}
