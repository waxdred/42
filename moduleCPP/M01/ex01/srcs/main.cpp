
#include "../includes/Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie *z;

	if (ac < 2)
		return (0);
	if (std::transform(av, _ForwardIterator1 __first1, _ForwardIterator1 __last1, _ForwardIterator2 __first2, _ForwardIterator __result, _BinaryOperation __op))
		return (0);
	z = zombieHorde(std::stoi(av[1]), av[2]);
	delete [] z;
	return (0);
}
