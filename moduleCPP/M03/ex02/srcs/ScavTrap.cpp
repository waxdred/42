#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <ostream>

ScavTrap::ScavTrap(void): ClapTrap(){
	std::cout << "ScavTrap constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_attack = 20;
	_isGuardingGate = false;
	return ;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name){
	std::cout << "ScavTrap Name constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_attack = 20;
	_isGuardingGate = false;
	return ;
}

ScavTrap::~ScavTrap(void){
	std::cout << "Destructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &Scavtrap){
	std::cout << "Copy constructor called" << std::endl;
	*this = Scavtrap;
	return;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &Scavtrap){
	if (&Scavtrap != this)
	{
		_name = Scavtrap._name;
		_hit = Scavtrap._hit;
		_energy = Scavtrap._energy;
		_attack = Scavtrap._attack;
		_isGuardingGate = Scavtrap._isGuardingGate;
	}
	return (*this);
}

void	ScavTrap::guardGate(void){
	if (_isGuardingGate)
		std::cout << "ScavTrap " << _name << " is already guarding th gate!" << std::endl;
	else if (!_hit)
		std::cout << "ScavTrap " << _name << " is dead!" << std::endl;
	else if (!_energy)
		std::cout << "ScavTrap " << _name << " has no energy to guard the gate" << std::endl;
	else{
		std::cout << "ScavTrap " << _name << " is going to guard the gate" << std::endl;
		_isGuardingGate = true;
	}
}

std::string	ScavTrap::getName(void)const{
	return (_name);
}

unsigned int	ScavTrap::getHit(void)const{
	return (_hit);
}

unsigned int	ScavTrap::getEnergy(void)const{
	return (_energy);
}

unsigned int	ScavTrap::getAttack(void)const{
	return (_attack);
}

bool	ScavTrap::getIsGuardingGate(void)const{
	return (_isGuardingGate);
}

std::ostream &operator << (std::ostream &o, const ScavTrap s){
	o << "info Player: " << s.getName() << "\nhit: "<< s.getHit() << "\nenergy:" << s.getEnergy() << "\nattack: " << s.getAttack() << "\nGate: "  << s.getIsGuardingGate() << std::endl;
	return (o);
}

