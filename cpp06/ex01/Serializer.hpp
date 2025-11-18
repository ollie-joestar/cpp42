#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
	Serializer(const Serializer&);
	Serializer();
	Serializer& operator=(const Serializer& other);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
	
#endif // SERIALIZER_HPP
