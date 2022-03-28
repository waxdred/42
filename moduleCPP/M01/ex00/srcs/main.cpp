
#include "../includes/Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie	*z[ac - 1];
	if (ac < 1)
		return (0);
	for (int i = 1; i < ac; i++)
	{
		z[i - 1] = newZombie(av[i]);
		randomChump(av[i]);
	}
	for (int i = 1; i < ac; i++)
		delete z[i - 1];
	return (0);
}
