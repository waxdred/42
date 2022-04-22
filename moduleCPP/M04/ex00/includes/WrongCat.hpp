#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
# include <iostream>

class	WrongCat : public WrongAnimal{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &wrongCat);
		~WrongCat(void);

		WrongCat &operator = (const WrongCat &wrongCat);
		void	makeSound(void);
		std::string	getType(void)const;
};
#endif
