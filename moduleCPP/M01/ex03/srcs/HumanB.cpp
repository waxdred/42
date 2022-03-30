
#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
	return;
}

HumanB::~HumanB(void){
	return ;
}

void HumanB::setWeapon(Weapon *weapon){
	this->_weapon = weapon;
}

void	HumanB::attack(void){
	std::cout << _name << " Attack with " << _weapon->getType() << std::endl;
}
