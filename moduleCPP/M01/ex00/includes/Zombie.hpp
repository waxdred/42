
#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class	Zombie
{
	private:
		std::string _Name;
	public:
		Zombie(std::string name);
		void		set_name(std::string name);
		std::string	get_name(void) const;
		~Zombie(void);
};
void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
#endif
