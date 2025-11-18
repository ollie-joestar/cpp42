#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

typedef struct type_casting {
	std::string type_name;
	void (*cast_function)(const std::string& input);
} type_casting_t;


std::string specials[] = {
	"nan", "nanf",
	"+inf", "-inf",
	"+inff", "-inff"
};

void	castToChar(const std::string& input) {

	unsigned char c = input[0 + (input[0] == '\'' ? 1 : 0)];
	if (!isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else
		std::cout << "char: '" << c << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: "
		<< std::fixed << std::setprecision(1)
		<< static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: "
		<< std::fixed << std::setprecision(1)
		<< static_cast<double>(c)  << std::endl;
}

void	castToInt(const std::string& input) {
	if (input.length() > 10 + (input[0] == '-' || input[0] == '+')) {
		std::cout << "Error: Invalid literal." << std::endl;
		return;
	}
	std::stringstream ss(input);
	int value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		std::cout << "Error: Invalid literal." << std::endl;
		return;
	}
	value = std::atoi(input.c_str());

	std::cout << "char: ";
	if ((value >= 0 && value < 128) && isprint(value))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value < 128)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: " << value << std::endl;

	float f_value = static_cast<float>(value);
	int test_value = static_cast<int>(f_value);
	if (test_value != value)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: "
			<< std::fixed << std::setprecision(1)
			<< f_value << "f" << std::endl;

	std::cout << "double: "
		<< std::fixed << std::setprecision(1) << static_cast<double>(value)  << std::endl;
}

void	castToFloat(const std::string& input) {
	std::cout<< "string length: " << input.length() << std::endl;
	std::stringstream ss(input.substr(0, input.length() - 1)); // Remove 'f' at the end
	float value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		std::cout << "Error: Invalid literal." << std::endl;
		return;
	}
	char *end;
	value = std::strtof(input.c_str(), &end);
	std::cout << input << std::endl;
	if (*end && input[input.length() - 1] != 'f') {
		std::cout << "Error: Invalid literal." << std::endl;
		return;
	}

	std::cout << "char: ";
	int	check_value = static_cast<int>(value);
	if (check_value < 0 || check_value > 127) {
		std::cout << "impossible" << std::endl;
	} else {
	if (isprint(static_cast<int>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	int int_value = static_cast<int>(value);
	if (static_cast<float>(int_value) != value)
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_value << std::endl;

	std::cout << "float: ";
	float f_value = static_cast<float>(value);
	if (static_cast<int>(f_value) != static_cast<int>(value))
		std::cout << "impossible" << std::endl;
	else {
	if (f_value - (float)static_cast<int>(f_value) == 0)
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::fixed << std::setprecision(7);
	std::cout << f_value << "f" << std::endl;
	}

	std::cout << "double: ";
	if (value - (double)static_cast<int>(value) == 0)
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::fixed << std::setprecision(15);
	std::cout << static_cast<double>(value) << std::endl;
}

void	castToDouble(const std::string &input) {
	std::cout<< "string length: " << input.length() << std::endl;
	std::stringstream ss(input);
	double value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		std::cout << "Error: Invalid literal." << std::endl;
		return;
	}
	std::cout<< "string length: " << input.length() << std::endl;
	char *end;
	value = std::strtod(input.c_str(), &end);
	if (*end) {
		std::cout << "Error: Invalid literal." << std::endl;
		return;
	}

	std::cout << "char: ";
	int	check_value = static_cast<int>(value);
	if (check_value < 0 || check_value > 127) {
		std::cout << "impossible" << std::endl;
	} else {
	if (isprint(static_cast<int>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	int int_value = static_cast<int>(value);
	if (static_cast<double>(int_value) != value)
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_value << std::endl;

	std::cout << "float: ";
	// if (value - (float)static_cast<int>(value) == 0)
	// 	std::cout << std::fixed << std::setprecision(1);
	// else
	// 	std::cout << std::fixed << std::setprecision(7);
	std::cout << static_cast<float>(value) << "f" << std::endl;

	std::cout << "double: ";
	if (value - (double)static_cast<int>(value) == 0)
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::fixed << std::setprecision(15);
	std::cout << static_cast<double>(value) << std::endl;
}

void	castToSpecial(const std::string& input) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input[0] == 'n') {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (input[0] == '+') {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

type_casting_t type_castings[] = {
	{"char", castToChar},
	{"int", castToInt},
	{"float", castToFloat},
	{"double", castToDouble},
	{"special", castToSpecial}
};
	

std::string trim(const std::string& str) {
	if (str.empty())
		return str;
	if (str.length() == 1 && isspace(str[0]))
		return str;
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, (last - first + 1));
}

std::string typeOfLiteral(const std::string& str) {
	size_t len = str.length();
	size_t last = len - 1;

	// Check for int
	for (size_t i = 0; i < len; ++i) {
		if (!isdigit(str[i]) && !(i == 0 && (str[i] == '+' || str[i] == '-')))
			break;
		if (i == last)
			return "int";
	}
	
	// Check for char
	if ((str[0] == '\''
	 && str[last] == '\'' 
	 && len == 3) ||
		(len == 1 && !isdigit(str[0])))
		return "char";

	// Check for float and double
	size_t dot_loc = str.find('.');
	if (dot_loc != std::string::npos
		&& dot_loc != 0 + (str[0] == '+' || str[0] == '-')
		&& dot_loc != last - (str[last] == 'f' || str[last] == 'F' ? 1 : 0)) {
		if (str[last] == 'f' || str[last] == 'F')
			return "float";
		else
			return "double";
	}

	// Check for pseudo-literals
	for (size_t i = 0; i < 6; ++i) {
		// std::cout << "Comparing " << str << " with " << specials[i] << std::endl;
		if (str == specials[i])
			return "special";
	}

	// If none of the above, return error
	return "error";
}

void ScalarConverter::convert(const std::string& literal) {
	std::string str = trim(literal);
	if (str.empty()) {
		std::cout << "Error: Invalid literal" << std::endl;
		return;
	}
	std::string type = typeOfLiteral(str);
	// std::cout << "Converting literal: \"" << str << "\"" << std::endl;
	// std::cout << "Detected type: " << type << std::endl;
	if (type == "int" && str.length() > 11) {
		std::cout << "Error: Unsupported literal" << std::endl;
		return;
	}
	if (type == "error") {
		std::cout << "Error: Skill issue." << std::endl;
		return;
	}
	for (size_t i = 0; i < sizeof(type_castings) / sizeof(type_castings[0]); ++i) {
		if (type == type_castings[i].type_name) {
			type_castings[i].cast_function(str);
			return;
		}
	}
}
