#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a;
	ScavTrap b("todo");

	std::cout << "Start player b:" << std::endl;
	std::cout << "\nPlayer b:\n" << b << std::endl;
	b.attack("toto");
	std::cout << "\nPlayer b:\n" << b << std::endl;
	b.takeDamage(45);
	std::cout << "\nPlayer b:\n" << b << std::endl;
	b.beRepaired(10);
	std::cout << "\nPlayer b:\n" << b << std::endl;
	b.guardGate();
	std::cout << "\nPlayer b:\n" << b << std::endl;

	std::cout << "Start player a:" << std::endl;
	std::cout << "\nPlayer a:\n" << a << std::endl;
	a.attack("toto");
	std::cout << "\nPlayer a:\n" << a << std::endl;
	a.takeDamage(45);
	std::cout << "\nPlayer a:\n" << a << std::endl;
	a.beRepaired(10);
	std::cout << "\nPlayer a:\n" << a << std::endl;
	a.guardGate();
	std::cout << "\nPlayer a:\n" << a << std::endl;

	return (0);
}
