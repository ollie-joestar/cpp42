#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class	Harl {
	private:
		void debug();
		void info();
		void warning();
		void error();
		
		static std::string levels[4];
		typedef void(Harl::*HarlMemberFunc)();
		static HarlMemberFunc functions[4];

	public:
		Harl();
		~Harl();

		void complain(std::string level);
};

#endif // HARL_HPP
