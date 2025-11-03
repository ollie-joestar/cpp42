#include "phonebook.hpp"

PhoneBook::PhoneBook() : contactNumber(0) {}

PhoneBook::~PhoneBook() {}

std::string formatForDisplay(const std::string &str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

std::string	cleanUpString(const std::string &str) {
	std::string cleaned;
	bool inEmptyness = false;

	for (size_t i = 0; i < str.length(); i++) {
		if (std::isspace(str[i])) {
			if (!inEmptyness && !cleaned.empty()) {
				cleaned += ' ';
				inEmptyness = true;
			}
		} else {
			cleaned += str[i];
			inEmptyness = false;
		}
	}
	return cleaned;
}

bool	isAscii(const std::string &str) {
	for (size_t i = 0; i < str.length(); i++) {
		char c = static_cast<unsigned char>(str[i]);
		if (c > 127 || (!std::isprint(c) && !std::isspace(c)))
			return false;
	}
	return true;
}

bool	checkNumber(const std::string &str) {
	size_t	i = 0;

	while (i < str.length() && std::isspace(str[i]))
		i++;
	if (i == str.length())
		return false;
	for (; i < str.length(); i++) {
		if (std::isspace(str[i]))
			break;
		if (!std::isdigit(str[i]))
			return false; 
	}
	while (i < str.length()) {
		if (!std::isspace(str[i]))
			return false;
		i++;
	}
	return true;
}

bool	PhoneBook::addContact() {
	std::string fName, lName, nName, pNumber, dSecret;

	std::cout << "Enter First Name: ";
	if (!std::getline(std::cin, fName) || fName.empty()) {
		if (fName.empty()) {
			std::cout << "No first name? Really?";
			std::cout << "\nInput error. Contact not added." << std::endl;
		} else
			std::cout << "\nInput error. Contact not added." << std::endl;
		return false;
	}
	if (!isAscii(fName)) {
		std::cout << "First name contains non-ASCII characters. Contact not added." << std::endl;
		return false;
	}
	fName = cleanUpString(fName);

	std::cout << "Enter Last Name: ";
	if (!std::getline(std::cin, lName) || lName.empty()) {
		if (lName.empty()) {
			if (fName == "Adele") {
				std::cout << "Hello, Adele. Welcome to the Phonebook." << std::endl;
				lName = "Laurie Blue Adkins";
			} else {
				std::cout << "You're not Adele. Gimme some last name";
				std::cout << "\nInput error. Contact not added." << std::endl;
				return false;
			}
		} else {
			std::cout << "\nInput error. Contact not added." << std::endl;
			return false;
		}
	}
	if (!isAscii(lName)) {
		std::cout << "Last name contains non-ASCII characters. Contact not added." << std::endl;
		return false;
	}
	lName = cleanUpString(lName);

	std::cout << "Enter Nickname: ";
	if (!std::getline(std::cin, nName) || nName.empty()) {
		if (nName.empty()) {
			std::cout << "You need a nickname. for example nOObmaster69";
			std::cout << "\nInput error. Contact not added." << std::endl;
		} else
			std::cout << "\nInput error. Contact not added." << std::endl;
		return false;
	}
	if (!isAscii(nName)) {
		std::cout << "Nickname contains non-ASCII characters. Contact not added." << std::endl;
		return false;
	}
	nName = cleanUpString(nName);

	std::cout << "Enter Phone Number: ";
	if (!std::getline(std::cin, pNumber) || pNumber.empty()) {
		if (pNumber.empty()) {
			std::cout << "You need a phone number. It's a PHONEBOOK!!!";
			std::cout << "\nInput error. Contact not added." << std::endl;
		} else
			std::cout << "\nInput error. Contact not added." << std::endl;
		return false;
	}
	if (!checkNumber(pNumber)) {
		std::cout << "Invalid phone number format. Only digits allowed. Contact not added." << std::endl;
		return false;
	}
	pNumber = cleanUpString(pNumber);

	std::cout << "Enter Darkest Secret: ";
	if (!std::getline(std::cin, dSecret) || dSecret.empty()) {
		if (dSecret.empty()) {
			std::cout << "Spill the tea. I know you have some";
			std::cout << "\nInput error. Contact not added." << std::endl;
		} else
			std::cout << "\nInput error. Contact not added." << std::endl;
		return false;
	}
	if (!isAscii(dSecret)) {
		std::cout << "Darkest secret contains non-ASCII characters. Contact not added." << std::endl;
		return false;
	}
	dSecret = cleanUpString(dSecret);

	contacts[contactNumber % 8].setContactInfo(fName, lName, nName, pNumber, dSecret);
	contactNumber++;
	return true;
}

void	PhoneBook::displayContacts() const {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < (contactNumber < 8 ? contactNumber : 8); i++) {
		std::cout << "|" << std::setw(10) << i + 1 << "|"
			<< std::setw(10) << formatForDisplay(contacts[i].getFirstName()) << "|"
			<< std::setw(10) << formatForDisplay(contacts[i].getLastName()) << "|"
			<< std::setw(10) << formatForDisplay(contacts[i].getNickname()) << "|"
			<< std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

bool	PhoneBook::searchContact() const {
	std::string indexStr;
	int index;

	std::cout << "Enter the index of the contact to view details: ";
	if (!std::getline(std::cin, indexStr)) {
		std::cout << "\nEOF. Returning to main menu." << std::endl;
		return false;
	}
	if (indexStr.empty()) {
		std::cout << "No index entered. Returning to main menu." << std::endl;
		return false;
	}
	if (indexStr.length() > 1 || !std::isdigit(indexStr[0])) {
		std::cout << "Invalid index." << std::endl;
		return false;
	}
	index = std::atoi(indexStr.c_str());
	if (index < 1 || index > 8 || index > contactNumber) {
		std::cout << "Invalid index." << std::endl;
		return false;
	}

	const Contact &contact = contacts[index - 1];
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	return true;
}
