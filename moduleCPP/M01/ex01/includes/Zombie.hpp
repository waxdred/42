
#include <iostream>
#include <algorithm>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class	Zombie
{
	private:
		std::string _Name;
	public:
		void		set_name(std::string name);
		std::string	get_name(void) const;
};
Zombie* zombieHorde(int N, std::string name);
void	annonce(Zombie z, int N);
#endif
