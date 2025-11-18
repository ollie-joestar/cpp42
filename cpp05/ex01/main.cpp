#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RST	"\033[0m"
#define GRN	"\033[32m"
#define YLW	"\033[33m"

int	main() {
	std::cout << GRN << "\n----- Form Class Test -----" << RST << std::endl;
	try {
		Form formInvalidHigh("InvalidHigh", 0, 20);
	} catch (const std::exception& e) {
		std::cerr << YLW <<  "Exception: " << e.what() << std::endl;
	}

	try {
		Form formInvalidLow("InvalidLow", 151, 20);
	} catch (const std::exception& e) {
		std::cerr << YLW <<  "Exception: " << e.what() << std::endl;
	}

	std::cout << GRN << "\n----- Signing Forms Test -----" << RST << std::endl;
	try {
		Bureaucrat	bureaucrat("Alice", 50);
		Form		formA("FormA", 30, 20);
		Form		formB("FormB", 60, 40);

		std::cout << bureaucrat << std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

		bureaucrat.signForm(formA);
		bureaucrat.signForm(formB);

		bureaucrat.setGrade(25);
		std::cout << "After incrementing grade 25 times:" << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(formA);
		bureaucrat.signForm(formB);
	} catch (const std::exception& e) {
		std::cerr << YLW <<  "Exception: " << e.what() << std::endl;
	}
}
