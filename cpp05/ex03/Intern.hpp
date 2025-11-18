#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
private:
	typedef AForm* (Intern::*FormCreator)(const std::string& target) const;

	AForm* createShrubberyForm(const std::string& target) const;
	AForm* createRobotomyForm(const std::string& target) const;
	AForm* createPresidentialForm(const std::string& target) const;

	typedef struct {
		std::string name;
		FormCreator creator;
	} FormType;

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif // INTERN_HPP
