#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap {
	private:
		const static unsigned int	defaultHitPoints = 10;
		const static unsigned int	defaultEnergyPoints = 10;
		const static unsigned int	defaultAttackDamage = 0;
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
		unsigned int	maxHP;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
