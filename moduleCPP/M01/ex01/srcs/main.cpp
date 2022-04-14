
#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie *z;

	z = zombieHorde(10, "foo");
	delete [] z;
	return (0);
}
