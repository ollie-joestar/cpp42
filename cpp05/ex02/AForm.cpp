#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned),
	  signGrade(other.signGrade), executeGrade(other.executeGrade) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string&	AForm::getName() const {
	return name;
}

bool	AForm::getIsSigned() const {
	return isSigned;
}

int	AForm::getSignGrade() const {
	return signGrade;
}

int	AForm::getExecuteGrade() const {
	return executeGrade;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (isSigned)
		throw AFormAlreadySignedException();
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os	<< "AForm Name: " << form.getName()
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "Nope")
	   	<< ", Sign Grade: " << form.getSignGrade()
		<< ", Execute Grade: " << form.getExecuteGrade();
	return os;
}
