#include "../includes/Zombie.hpp"

void	annonce(Zombie z, int N)
{
	std::cout << "Zombie " << N << ": " << z.get_name() << std::endl;
}


Zombie* zombieHorde(int N, std::string name)
{
	Zombie *z = new Zombie[N];

	for (int i = 0; i < N; i++)
		z[i].set_name(name);
	return (z);
}
