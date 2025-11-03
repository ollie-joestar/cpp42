#include "phonebook.hpp"

int	main(void) {
	std::string command;
	PhoneBook phoneBook;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH or EXIT" << std::endl;
	while (true) {
		std::cout << "Enter command: ";
		// Handle EOF (Ctrl+D)
		if (!std::getline(std::cin, command)) {
			std::cout << "\nEOF detected. Exiting PhoneBook. Goodbye!" << std::endl;
			return 1;
		}
		if (command == "EXIT") {
			std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
			return 0;
		} else if (command == "ADD") {
			if (phoneBook.addContact()) {
				std::cout << "Contact added successfully!" << std::endl;
			} 
			if (std::cin.eof()) {
				std::cout << "EOF detected. Exiting PhoneBook. Goodbye!" << std::endl;
				return 1;
			}
		} else if (command == "SEARCH") {
			phoneBook.displayContacts();
			if (!phoneBook.searchContact()) {
				if (std::cin.eof()) {
					std::cout << "EOF detected. Exiting PhoneBook. Goodbye!" << std::endl;
					return 1;
				}
			}
		// } else if (!command.empty()) {
		// 	std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;
		}
	}
}
