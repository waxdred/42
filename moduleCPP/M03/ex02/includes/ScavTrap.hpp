#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
# include <iostream>
#include <string>

class	ScavTrap : public ClapTrap {
	private:	
		bool	_isGuardingGate;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &ScavTrap);
		~ScavTrap(void);
		ScavTrap &operator = (const ScavTrap &Scavtrap);
		void	guardGate(void);
		std::string	getName(void)const;
		unsigned int	getHit(void)const;
		unsigned int	getEnergy(void)const;
		unsigned int	getAttack(void)const;
		bool 	getIsGuardingGate(void)const;
};

std::ostream &operator << (std::ostream &o, const ScavTrap scavtrap);
#endif
