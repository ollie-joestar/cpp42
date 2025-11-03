#include "Harl.hpp"

std::string Harl::levels[4] = 
	{ "DEBUG" , "INFO", "WARNING" , "ERROR" };

Harl::HarlMemberFunc Harl::functions[4] =
	{ &Harl::debug, &Harl::info , &Harl::warning, &Harl::error };

Harl::Harl () {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout
	<< "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	<< std::endl;
}

void Harl::info() {
	std::cout
	<< "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger in my burger! If you did, I wouldn't be asking for more!"
	<< std::endl;
}

void Harl::warning() {
	std::cout
	<< "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
	<< std::endl;
}

void Harl::error() {
	std::cout
	<< "[ERROR] This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void Harl::complain(std::string level) {
	int	i = 0;
	for (; level != this->levels[i]; i++) {
		if (i == 4) {
			std::cout << "[SKILL ISSUE] Unknown level!" << std::endl;
			return ;
		}
	};
	(this->*functions[i])();
}
