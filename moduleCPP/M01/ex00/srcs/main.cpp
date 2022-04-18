
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z = new Zombie("Yolo");

	z->annonce();
	delete z;
	z = newZombie("Todo");
	z->annonce();
	delete z;
	randomChump("Zoulou");
	return (0);
}
