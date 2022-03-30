
#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string _weapon;
	public:
		Weapon(std::string weapon);
		~Weapon(void);
		std::string getType(void) const;
		void setType(std::string name);
};

#endif
