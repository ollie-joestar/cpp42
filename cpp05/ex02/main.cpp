#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RST	"\033[0m"
#define GRN	"\033[32m"
#define YLW	"\033[33m"

int	main() {
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	goon("Goon", 150);

	std::cout << GRN << "\n--- Creating Forms ---\n" << RST;
	PresidentialPardonForm	presForm("Osama bin Laden");
	std::cout << presForm << std::endl;
	RobotomyRequestForm		robotForm("Bender");
	std::cout << robotForm << std::endl;
	ShrubberyCreationForm	shrubForm("Garden");
	std::cout << shrubForm << std::endl;

	std::cout << GRN << "\n--- Signing Forms ---\n" << RST;
	goon.signForm(presForm);
	boss.signForm(presForm);
	goon.signForm(robotForm);
	boss.signForm(robotForm);
	goon.signForm(shrubForm);
	boss.signForm(shrubForm);

	std::cout << GRN << "\n--- Executing Forms as Goon ---\n" << RST;
	goon.executeForm(presForm);
	goon.executeForm(robotForm);
	goon.executeForm(shrubForm);

	std::cout << GRN << "\n--- Executing Forms as Boss ---\n" << RST;
	boss.executeForm(presForm);
	boss.executeForm(robotForm);
	boss.executeForm(shrubForm);

	return 0;
}
