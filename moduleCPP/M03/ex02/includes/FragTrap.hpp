#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap{
	private:	
		
	public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(const FragTrap &FragTap);
		~FragTrap(void);

		FragTrap &operator = (const FragTrap &fragTap);
		void	highFivesGuys();
		std::string	getName(void)const;
		unsigned int	getHit(void)const;
		unsigned int	getEnergy(void)const;
		unsigned int	getAttack(void)const;
};
std::ostream &operator << (std::ostream &o, const FragTrap scavtrap);
#endif
