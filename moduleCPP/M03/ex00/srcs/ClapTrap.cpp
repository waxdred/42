#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("None"), _hit(10), _energy(10), _attack(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _attack(0){
	std::cout << "Default constructor name arg called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void){
	std::cout << "Destructor called " << _name << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &ClapTrap){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = ClapTrap;
	return;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &rhs){
	if (&rhs != this)
	{
		_name = rhs._name;
		_hit = rhs._hit;
		_energy = rhs._energy;
		_attack = rhs._attack;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target){
	if (_hit == 0)
		std::cout << _name << ": is Dead" << std::endl;
	else if (_energy == 0)
		std::cout << _name << ": has no energy to attack" << std::endl;
	else
	{
		std::cout << _name << ": attack " << target << std::endl;
		_energy--;
	}
	return ;
}

void ClapTrap::takeDamage(unsigned int amount){
	int	tmp;
	if (_hit == 0)
		std::cout << _name << ": is already dead" << std::endl;
	else{
		std::cout << _name << ": took " << amount << " of damage" << std::endl;
		tmp = _hit - amount;
		if (tmp <= 0){
			_hit = 0;
			std::cout << _name << ": is dead" << std::endl;
		}
		else{
			_hit = tmp;
			std::cout << _name << ": took " << amount << " and has " << tmp << " hit left" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (_hit <= 0)
		std::cout << _name << ": is already dead" << std::endl;
	else{
		std::cout << _name << ": took " << amount << " of Repaire" << std::endl;
		_energy += amount;
	}
}


