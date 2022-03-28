
#include "../includes/Zombie.hpp"

void	Zombie::set_name(std::string name)
{
	this->_Name = name;
}

std::string	Zombie::get_name(void) const
{
	return (this->_Name);
}
