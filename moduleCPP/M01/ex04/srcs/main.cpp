#include "Sed.hpp"

int	main(int ac, char **av)
{
	Sed  *sed = new Sed;

	std::cout << ac << std::endl;
	if (ac != 4)
		std::cout << "Error: Filename s1 s2" << std::endl;
	else if (sed->setSed(av[1]))
	{
		sed->sedFile(av[2], av[3]);
		sed->readFile();
		std::cout << "Succes !!!" << std::endl;;
	}
	delete sed;
	return (0);
}
