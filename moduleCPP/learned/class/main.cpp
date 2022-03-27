#include "rational.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	Rational r(50, 2);

	if (ac != 3)
	{
		std::cerr << "error argument";
		return (-1);
	}
	/* std::cout << "[" << r.getNum() << "/" << r.getDnum() << "]" << std::endl; */
	std::cout << r << std::endl;
	r.setNum(std::atoi(av[1]));
	r.setDnum(std::atoi(av[2]));

	/* std::cout << "[" << r.getNum() << "/" << r.getDnum() << "]" << std::endl; */
	std::cout << r << std::endl;
	return (0);
}
