#include "ClapTrap.hpp"

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
	std::cout << "\n----- Testing destructors -----" << std::endl;

	return 0;
}
