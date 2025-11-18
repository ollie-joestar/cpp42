#include "Serializer.hpp"
#include "Data.hpp"
#include "iostream"

#define GRN "\033[32m"
#define RST "\033[0m"

int	main(void)
{
	Data given;
	Data *other;
	uintptr_t	uint;

	given.value = 42;

	std::cout << GRN "\nSerializing given data with value 42" RST << std::endl;
	std::cout << GRN "Deserializing to other data pointer" RST <<  std::endl;
	uint = Serializer::serialize(&given);
	other = Serializer::deserialize(uint);

	std::cout << "Given data value: " << given.value << std::endl;
	std::cout << "Other data value: " << other->value << std::endl;
	
	std::cout << GRN "\nModifying given data value to 69..." RST << std::endl;
	given.value = 69;

	std::cout << "Given data value: " << given.value << std::endl;
	std::cout << "Other data value: " << other->value << std::endl;

	std::cout << GRN "\nModifying other data value to 2147483647..." RST << std::endl;
	other->value = 2147483647;

	std::cout << "Given data value: " << given.value << std::endl;
	std::cout << "Other data value: " << other->value << std::endl;
}
