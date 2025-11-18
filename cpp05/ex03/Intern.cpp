#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Default constructor called for Intern" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "Copy constructor called for Intern" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cout << "Assignment operator called for Intern" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Destructor called for Intern" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {

	FormType formTypes[] = {
		{"shrubbery creation", &Intern::createShrubberyForm},
		{"robotomy request", &Intern::createRobotomyForm},
		{"presidential pardon", &Intern::createPresidentialForm}
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == formTypes[i].name) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formTypes[i].creator)(target);
		}
	}

	std::cout
		<< "\033[031mIntern could not create " << formName
		<< " because it is unknown.\033[0m" << std::endl;
	return NULL;
}

AForm* Intern::createShrubberyForm(const std::string& target) const {
	std::cout << "Creating Shrubbery Creation Form for target: " << target << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) const {
	std::cout << "Creating Robotomy Request Form for target: " << target << std::endl;
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) const {
	std::cout << "Creating Presidential Pardon Form for target: " << target << std::endl;
	return new PresidentialPardonForm(target);
}
