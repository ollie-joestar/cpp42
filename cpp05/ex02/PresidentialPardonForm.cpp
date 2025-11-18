#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", 25, 5), target("default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", 25, 5), target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), target(other.target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
