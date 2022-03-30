
#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string _weapon;
	public:
		Weapon(std::string weapon);
		std::string get_weapon(void) const;
		void set_weapon(std::string name);
};

#endif
