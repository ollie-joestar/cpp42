#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	std::cout << "----- Testing ClapTrap -----" << std::endl;
	ClapTrap	claptrap("CL4P-TP");

	claptrap.attack("Enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.beRepaired(3);
	claptrap.takeDamage(12);
	claptrap.beRepaired(5);
	claptrap.attack("Enemy");

	std::cout << "\n----- Testing ScavTrap -----" << std::endl;
	ScavTrap	scavtrap("SC4V-TP");
	scavtrap.attack("Enemy");
	scavtrap.beRepaired(10);
	scavtrap.takeDamage(15);
	scavtrap.beRepaired(10);
	scavtrap.takeDamage(25);
	scavtrap.beRepaired(40);
	scavtrap.attack("Enemy");
	scavtrap.guardGate();
	scavtrap.guardGate();
	scavtrap.takeDamage(200);
	scavtrap.guardGate();

	std::cout << "\n----- Testing FragTrap -----" << std::endl;
	FragTrap	fragtrap("FR4G-TP");
	fragtrap.attack("Enemy");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(15);
	fragtrap.attack("Enemy");
	fragtrap.takeDamage(50);
	fragtrap.beRepaired(60);
	fragtrap.attack("Enemy");
	fragtrap.highFivesGuys();
	fragtrap.takeDamage(200);
	fragtrap.highFivesGuys();
	std::cout << "\n----- Testing destructors -----" << std::endl;

	return 0;
}
