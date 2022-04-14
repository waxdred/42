
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
	return;
}

HumanA::~HumanA(void){
	return ;
}

void	HumanA::attack(void){
	std::cout << _name << " Attack with " << _weapon.getType() << std::endl;
}
