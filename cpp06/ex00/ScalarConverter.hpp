#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
	static void convert(const std::string& literal);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
};

// Helper function to trim whitespace from both ends of a string
std::string trim(const std::string& str);

#endif // SCALARCONVERTER_HPP
