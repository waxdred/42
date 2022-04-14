
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	std::cout << name << ": " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed Zombie" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_Name = name;
}

std::string	Zombie::get_name(void) const
{
	return (this->_Name);
}
