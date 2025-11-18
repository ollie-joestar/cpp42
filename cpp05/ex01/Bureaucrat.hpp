#ifndef BURAUCRAT_HPP
#define BURAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat {

private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	
	const std::string&	getName() const;
	int					getGrade() const;
	// For testing purposes only
	void				setGrade(int grade);
	
	void				incrementGrade();
	void				decrementGrade();

	void				signForm(Form &form) const;

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BURAUCRAT_HPP
