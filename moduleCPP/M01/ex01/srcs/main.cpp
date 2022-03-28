
#include "../includes/Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie *z;

	if (ac < 2)
		return (0);
	z = zombieHorde(std::stoi(av[1]), av[2]);
	delete [] z;
	return (0);
}
