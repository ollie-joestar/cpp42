#include <iostream>
#include <cctype>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			unsigned char c = static_cast<unsigned char>(argv[i][j]);
			if (c > 127 || c < 0 || (!isprint(c) && !isspace(c)))
			{
				std::cout << "\r\33[2K";
				std::cout << "* FOREIGN SOUNDING NOISE *" << std::endl;
				return 1;
			}
			std::cout << static_cast<char>(toupper(c));
		}
	}
	std::cout << std::endl;
	return 0;
}
