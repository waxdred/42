
#include "Zombie.hpp"

int	main(void)
{
	Zombie *z;

	z = zombieHorde(10, "foo");
	for (int i = 0; i < 10; i++)
		annonce(z[i], 10);
	delete [] z;
	return (0);
}
