
#include "../includes/Sed.hpp"
#include <iostream>
#include <fstream>

int	main(void)
{
	std::fstream ifs;

	ifs.open("../test", );
	if (ifs.is_open())
	{
		Sed sed = Sed(ifs, "git", "test");
		sed.sed_file();
	}
	else
		std::cerr << "Error file not found" << std::endl;
	return (0);
}
