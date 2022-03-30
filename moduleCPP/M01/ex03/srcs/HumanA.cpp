
#include "../includes/HumanA.hpp"

std::string HumanA::get_name(void) const
{
	return (this->_name);
}

void HumanA::set_name(std::string name)
{
	this->_name = name;
}

HumanA::HumanA(std::string name)
{
	this->set_name(name);
}
