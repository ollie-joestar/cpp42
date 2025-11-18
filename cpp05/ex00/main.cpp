#include <iostream>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

int	main() {
	std::cout << GREEN << "\n----- Bureaucrat Class Test -----" << RESET << std::endl;
	try {
		Bureaucrat	bureaucrat1("Alice", 2);
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.incrementGrade();
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.incrementGrade(); // This should throw an exception
	} catch (const std::exception& e) {
		std::cerr << YELLOW << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	bureaucrat2("Bob", 149);
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.decrementGrade();
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.decrementGrade(); // This should throw an exception
	} catch (const std::exception& e) {
		std::cerr << YELLOW << "Exception: " << e.what() << std::endl;
	}

	std::cout << GREEN << "\n----- Testing Invalid Grades -----" << RESET << std::endl;
	try {
		Bureaucrat	bureaucrat3("Charlie", 0); // This should throw an exception
	} catch (const std::exception& e) {
		std::cerr << YELLOW << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	bureaucrat4("Dave", 151); // This should throw an exception
	} catch (const std::exception& e) {
		std::cerr << YELLOW << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
