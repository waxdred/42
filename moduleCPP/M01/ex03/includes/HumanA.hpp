
#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
	private:
		std::string _name;
	public:
		HumanA(std::string name, Weapon weapon);
		std::string get_name(void) const;
		void set_name(std::string name);
};

#endif
