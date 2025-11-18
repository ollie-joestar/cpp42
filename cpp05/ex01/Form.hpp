#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
public:
	Form();
	Form(const std::string& name, int signGrade, int executeGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

	void				beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "\033[31mGrade is too high!\033[0m";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "\033[31mGrade is too low!\033[0m";
		}
	};

	class FormAlreadySignedException : public std::exception {
	public:
		const char* what() const throw() {
			return "\033[31mForm is already signed!\033[0m";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP
