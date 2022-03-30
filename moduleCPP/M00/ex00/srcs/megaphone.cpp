#include <algorithm>
#include <iostream>
#include <string>

void StringToupper(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(),::toupper);
	std::cout << s;
}

int	main(int	ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < ac; i++)
	{
		StringToupper((std::string)av[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
