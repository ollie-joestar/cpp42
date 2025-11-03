#include <iostream>
#include <fstream>
#include <string>

std::string searchAndReplace(std::string line, const std::string& s1, const std::string& s2) {
	std::size_t pos = 0;
	std::string result;
	std::size_t found;

	while ((found = line.find(s1, pos)) != std::string::npos) {
		result.append(line.substr(pos, found - pos));
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(line.substr(pos));

	return result;
}

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Enter filename, stringToFind and stringToReplace" << std::endl;
		return 1;
	}

	std::ifstream inFile(argv[1]);
	if (!inFile) {
		std::cerr << "Failed to open file" << std::endl;
		return 2;
	}

	std::string outName = argv[1];
	outName += ".replace";
	std::ofstream outFile(outName.c_str());
	if (!outFile) {
		std::cerr << "Failed to create file" << std::endl;
		inFile.close();
		return 2;
	}

	std::string line;
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "String to find must not be empty" << std::endl;
		inFile.close();
		outFile.close();
		return 3;
	}

	while (std::getline(inFile, line))
		outFile << searchAndReplace(line, s1, s2) << std::endl;

	inFile.close();
	outFile.close();
	
	return 0;
}
