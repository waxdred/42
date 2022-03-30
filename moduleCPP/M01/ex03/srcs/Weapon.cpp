
#include "../includes/Weapon.hpp"

std::string Weapon::get_weapon(void)
{
	return (this->_weapon);
}

Weapon::Weapon(std::string weapon)
{
	this->set_weapon(weapon);
}
