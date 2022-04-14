#include "Sed.hpp"
#include <iostream>
#include <fstream>

int	main(void)
{
	std::fstream file;
	Sed sed(file, "test");

	sed.sed_file("make", "test");
	return (0);
}
