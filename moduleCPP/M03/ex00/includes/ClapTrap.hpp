#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

		class	ClapTrap{
			private:	
				std::string _name;
				unsigned int _hit;
				unsigned int _energy;
				unsigned int _attack;
				
			public:
				ClapTrap(void);
				ClapTrap(std::string name);
				ClapTrap(const ClapTrap &ClapTrap);
				~ClapTrap(void);
	
				ClapTrap &operator = (const ClapTrap &rhs);
				void attack(const std::string& target);
				void takeDamage(unsigned int amount);
				void beRepaired(unsigned int amount);
		};
#endif
