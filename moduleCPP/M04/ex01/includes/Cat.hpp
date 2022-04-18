#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
# include <iostream>

class	Cat : public Animal{
	private:	
		std::string _type;
		Brain *Brain;
	public:
		Cat(void);
		Cat(const Cat &Cat);
		~Cat(void);

		Cat &operator = (const Cat &cat);
		void	makeSound(void);
		std::string	getType(void)const;
};
#endif
