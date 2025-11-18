#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Anakin"), grade(150) {
	std::cout << "Default constructor called for Bureaucrat: " << name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout
		<< "Constructor called for Bureaucrat: "
		<< name << " with grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout
		<< "Copy constructor called for Bureaucrat: "
		<< name << " with grade " << grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	std::cout
		<< "Assignment operator called for Bureaucrat: "
		<< name << " with grade " << grade << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "Destructor called for Bureaucrat: " << name << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	std::cout
		<< "Incrementing grade of " << name << " from "
		<< grade << " to " << (grade - 1) << std::endl;
	if (grade <= 1)
		throw GradeTooHighException();
	--grade;
}

void Bureaucrat::decrementGrade() {
	std::cout
		<< "Decrementing grade of " << name << " from "
		<< grade << " to " << (grade + 1) << std::endl;
	if (grade >= 150)
		throw GradeTooLowException();
	++grade;
}

void	Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout
		<< "Changing grade of " << name
		<< " from " << this->grade
		<< " to " << grade << std::endl;
	this->grade = grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout
			<< "\033[33m" << name
			<< " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}
