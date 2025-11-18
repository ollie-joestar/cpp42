#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define RST	"\033[0m"
#define GRN	"\033[32m"
#define YLW	"\033[33m"

int	main() {

	std::cout << GRN << "-- Creating Intern --" << RST << std::endl;

	Intern	someRandomIntern;
	
	std::cout << GRN << "\n-- Making Shrubbery Creation Form --" << RST << std::endl;

	AForm*	shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Home");

	std::cout << GRN << "\n-- Making Robotomy Request Form --" << RST << std::endl;

	AForm*	robotomyForm = someRandomIntern.makeForm("robotomy request", "That big hole");

	std::cout << GRN << "\n-- Making Presidential Pardon Form --" << RST << std::endl;

	AForm*	presidentialForm = someRandomIntern.makeForm("presidential pardon", "Osama bin Laden");

	std::cout << GRN << "\n-- Making Unknown Form --" << RST << std::endl;

	AForm*	unknownForm = someRandomIntern.makeForm("unknown form", "Nobody");

	(void)unknownForm; // To avoid unused variable warning

	std::cout << GRN << "\n-- Creating Bureaucrats --" << RST <<  std::endl;

	Bureaucrat	boss("Boss", 1);
	Bureaucrat	goon("Goon", 150);


	std::cout << GRN << "\n-- Signing and Executing Forms --" << RST << std::endl;

	goon.signForm(*shrubberyForm);
	boss.signForm(*shrubberyForm);
	goon.executeForm(*shrubberyForm);
	boss.executeForm(*shrubberyForm);
	goon.signForm(*robotomyForm);
	boss.signForm(*robotomyForm);
	goon.executeForm(*robotomyForm);
	boss.executeForm(*robotomyForm);
	goon.signForm(*presidentialForm);
	boss.signForm(*presidentialForm);
	goon.executeForm(*presidentialForm);
	boss.executeForm(*presidentialForm);

	std::cout << GRN << "\n-- Cleaning Up --" << RST << std::endl;
	delete shrubberyForm;
	delete robotomyForm;
	delete presidentialForm;

	return 0;
}
