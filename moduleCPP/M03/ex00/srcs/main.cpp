#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("todo");
	ClapTrap b;
	ClapTrap c(a);
	ClapTrap d("foo");

	std::cout << std::endl << " == A ACTIONS == " << std::endl;
	a.attack("Thor");
	a.beRepaired(4);
	a.takeDamage(3);
	a.takeDamage(30);
	a.attack("todo");
	a.beRepaired(10);
	a.takeDamage(50);
	std::cout << std::endl << " == B ACTIONS == " << std::endl;
	b.attack("Iron Man");
	b.takeDamage(9);
	b.beRepaired(2);
	b.takeDamage(3);
	b.attack("Thor");

	return (0);
}
