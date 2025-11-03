#include "Zombie.hpp"

// Its on heap so delete() if afterwards!!!
Zombie	*newZombie(std::string name) {

	Zombie* zombie = new (std::nothrow) Zombie();

	if (!zombie)
		return NULL;

	zombie->setName(name);
	return zombie;
}
