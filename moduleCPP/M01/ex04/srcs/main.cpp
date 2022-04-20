#include "Sed.hpp"

int	main(int ac, char **av)
{
	std::fstream fdin;
	std::fstream fdout;
	Sed sed(fdin, fdout);

	if (ac < 4)
	{
		std::cout << "Error:\nFilename s1 s2" << std::endl;;
		return (-1);
	}
	if (sed.setSed(av[1]))
	{
		sed.sedFile(av[2], av[3]);
		sed.readFile();
		std::cout << "Succes !!!" << std::endl;;
	}
	return (0);
}
