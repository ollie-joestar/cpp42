#include "Zombie.hpp"

int	main(void) {

	Zombie basicZombie;
	basicZombie.setName("Basic");
	basicZombie.announce();

	std::cout << "-----" << std::endl;

	Zombie* heapZombie = new Zombie();
	if (!heapZombie) {
		std::cerr << "Memory allocation failed" << std::endl;
		return 1;
	}
	heapZombie->setName("Heap");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "-----" << std::endl;

	Zombie* newHeapZombie = NULL;
	newHeapZombie = newZombie("NewHeap");
	if (!newHeapZombie) {
		std::cerr << "Memory allocation failed" << std::endl;
		return 1;
	}
	newHeapZombie->announce();
	delete newHeapZombie;

	std::cout << "-----" << std::endl;

	randomChump("RandomChumpZombie");

	std::cout << "-----" << std::endl;

	return 0;
}
