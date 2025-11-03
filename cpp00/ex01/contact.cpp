#include "contact.hpp"

Contact::Contact() {
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}

Contact::~Contact() {}

void Contact::setContactInfo(std::string fName, std::string lName,
							 std::string nName, std::string pNumber,
							 std::string dSecret) {
	firstName = fName;
	lastName = lName;
	nickname = nName;
	phoneNumber = pNumber;
	darkestSecret = dSecret;
} 

std::string Contact::getFirstName() const {
	return firstName;
}

std::string Contact::getLastName() const {
	return lastName;
}

std::string Contact::getNickname() const {
	return nickname;
}

std::string Contact::getPhoneNumber() const {
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return darkestSecret;
}
