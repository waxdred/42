#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
# include <iostream>

class	Dog : public Animal{
	private:	
		std::string _type;
		Brain *Brain;
	public:
		Dog(void);
		Dog(const Dog &Dog);
		~Dog(void);

		Dog &operator = (const Dog &dog);
		void	makeSound(void);
		std::string	getType(void)const;
};
#endif
