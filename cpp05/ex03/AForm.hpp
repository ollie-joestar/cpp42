#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
public:
	AForm();
	AForm(const std::string& name, int signGrade, int executeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

	void				beSigned(const Bureaucrat& bureaucrat);
	virtual void		execute(const Bureaucrat& executor) const = 0;

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

	class AFormAlreadySignedException : public std::exception {
	public:
		const char* what() const throw() {
			return "\033[31mAForm is already signed!\033[0m";
		}
	};

	class AFormAlreadyExecutedException : public std::exception {
	public:
		const char* what() const throw() {
			return "\033[31mAForm is already executed!\033[0m";
		}
	};

	class AFormNotSignedException : public std::exception {
	public:
		const char* what() const throw() {
			return "\033[31mAForm is not signed!\033[0m";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // AFORM_HPP
