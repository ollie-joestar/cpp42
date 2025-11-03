#include <string>
#include <iostream>

int	main() {
	std::string theString = "HI THIS IS BRAIN";
	std::string *stringPTR = &theString;
	std::string &stringREF = theString;

	std::cout << "Address of theString itself:\t" << &theString << std::endl;
	std::cout << "Address held by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Address held by stringREF:\t" << &stringREF << std::endl;

	std::cout << "----------" << std::endl;

	std::cout << "Value of theString:\t\t" << theString << std::endl;
	std::cout << "Value at stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "Value at stringREF:\t\t" << stringREF << std::endl;

	std::cout << "----------" << std::endl;
	std::cout << "Changing the value of theString to 'NEW VALUE'" << std::endl;
	theString = "NEW VALUE";

	std::cout << "----------" << std::endl;

	std::cout << "Value of theString:\t\t" << theString << std::endl;
	std::cout << "Value at stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "Value at stringREF:\t\t" << stringREF << std::endl;
	
	return 0;
}
