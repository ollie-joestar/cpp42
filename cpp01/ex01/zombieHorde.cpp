#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name) {

	if (n <= 0)
		return NULL;

	Zombie *horde = new (std::nothrow) Zombie[n];

	if (!horde)
		return NULL;

	for (int i = 0; i < n; i++)
		horde[i].setName(name);

	return horde;
}
