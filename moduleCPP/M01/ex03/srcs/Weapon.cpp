
#include "../includes/Weapon.hpp"

std::string Weapon::getType(void) const{
	return (this->_weapon);
}

void Weapon::setType(std::string name){
	this->_weapon = name;
}

Weapon::Weapon(std::string weapon){
	this->setType(weapon);
}

Weapon::~Weapon(void){
	return ;
}
