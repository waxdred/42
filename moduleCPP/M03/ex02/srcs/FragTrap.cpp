#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
	std::cout << "[FragTag] Default constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_attack = 30;
	return ;
}

FragTrap::FragTrap(std::string const name): ClapTrap(name) {
	std::cout << "[FragTag] Default constructor called. New name" << std::endl;
	_hit = 100;
	_energy = 100;
	_attack = 30;
	return ;
}

FragTrap::~FragTrap(void){
	std::cout << "[FragTrap] Destructor called " << _name << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &fragTag){
	std::cout << "[FragTrap] Copy constructor called" << std::endl;
	*this = fragTag;
	return;
}

FragTrap & FragTrap::operator= (const FragTrap &fragTrap) {
	std::cout << "[FRAGTRAP] Copy assignment operator called" << std::endl;
	if (this != &fragTrap) {
		_name = fragTrap._name;
		_hit = fragTrap._hit;
		_energy = fragTrap._energy;
		_attack = fragTrap._attack;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void){
	if (!_hit)
		std::cout << "FragTrap " << _name << " is already dead!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " ask for hight five" << std::endl;
}

std::string	FragTrap::getName(void)const{
	return (_name);
}

unsigned int	FragTrap::getHit(void)const{
	return (_hit);
}

unsigned int	FragTrap::getEnergy(void)const{
	return (_energy);
}

unsigned int	FragTrap::getAttack(void)const{
	return (_attack);
}

std::ostream &operator << (std::ostream &o, const FragTrap s){
	o << "info Player: " << s.getName() << "\nhit: "<< s.getHit() << "\nenergy:" << s.getEnergy() << "\nattack: " << s.getAttack() << std::endl;
	return (o);
}



