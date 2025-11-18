#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

#define GRN "\033[32m"
#define RST "\033[0m"

Base* generate() {
	int chance = std::rand() % 3 + 1;
	switch (chance) {
		case 1:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 2:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 3:
			std::cout << "Generated C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A by pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B by pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C by pointer" << std::endl;
	else
		std::cout << "Unknown Pointer Type" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "Identified A by reference" << std::endl;
		(void)a;
		return;
	} catch (std::exception& e) {}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "Identified B by reference" << std::endl;
		(void)b;
		return;
	} catch (std::exception& e) {}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "Identified C by reference" << std::endl;
		(void)c;
		return;
	} catch (std::exception& e) {}
	std::cout << "Unknown Reference Type" << std::endl;
}

int	main() {
	std::srand(std::time(0));

	std::cout << GRN << "----- Generating random instances -----" << RST << std::endl;
	Base* first = generate();
	Base* second = generate();
	Base* third = generate();
	Base* bad = NULL;


	std::cout << GRN << "----- Identifying types for first -----" << RST << std::endl;
	identify(first);
	identify(*first);

	std::cout << GRN << "----- Identifying types for second -----" << RST << std::endl;
	identify(second);
	identify(*second);

	std::cout << GRN << "----- Identifying types for third -----" << RST << std::endl;
	identify(third);
	identify(*third);

	std::cout << GRN << "----- Identifying types for invalid data (NULL) -----" << RST << std::endl;
	identify(bad);
	identify(*bad);

	delete first;
	delete second;
	delete third;
	return 0;
}
