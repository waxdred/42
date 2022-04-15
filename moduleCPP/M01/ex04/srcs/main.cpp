#include "Sed.hpp"
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::fstream file;
	Sed sed(file);

	if (ac < 4)
	{
		std::cout << "Error:\nFilename s1 s2" << std::endl;;
		return (-1);
	}
	if (sed.setSed(av[1]))
	{
		sed.sedFile(av[2], av[3]);
		std::cout << "Succes !!!" << std::endl;;
	}
	return (0);
}
