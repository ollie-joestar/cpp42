#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150) {}

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned),
	  signGrade(other.signGrade), executeGrade(other.executeGrade) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string&	Form::getName() const {
	return name;
}

bool	Form::getIsSigned() const {
	return isSigned;
}

int	Form::getSignGrade() const {
	return signGrade;
}

int	Form::getExecuteGrade() const {
	return executeGrade;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (isSigned)
		throw FormAlreadySignedException();
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os	<< "Form Name: " << form.getName()
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "Nope")
	   	<< ", Sign Grade: " << form.getSignGrade()
		<< ", Execute Grade: " << form.getExecuteGrade();
	return os;
}
