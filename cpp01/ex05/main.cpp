#include "Harl.hpp"

int	main() {
	Harl harl;

	std::cout << "\nTesting debug" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\nTesting info" << std::endl;
	harl.complain("INFO");
	std::cout << "\nTesting warning" << std::endl;
	harl.complain("WARNING");
	std::cout << "\nTesting error" << std::endl;
	harl.complain("ERROR");
	std::cout << "\nTesting unknown level" << std::endl;
	harl.complain("BOSS");

	return 0;
}
