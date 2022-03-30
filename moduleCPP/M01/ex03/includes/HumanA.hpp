
#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void attack(void);
};

#endif
