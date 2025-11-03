#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iomanip>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cctype>

class PhoneBook {
   private:
	Contact contacts[8];
	int contactNumber;

   public:
	PhoneBook();
	~PhoneBook();

	bool addContact();

	void displayContacts() const;
	bool searchContact() const;
};

#endif // PHONEBOOK_HPP
