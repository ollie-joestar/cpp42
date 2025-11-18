#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), target("default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::cout << "Bzzzzzz... Vrrrrrr... " << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << "\033[32m"
			<< this->target << " has been robotomized successfully."
			<< "\033[0m" << std::endl;
	else
		std::cout
			<< "\033[33mRobotomy failed on " << this->target
			<< ".\033[0m" << std::endl;
}
