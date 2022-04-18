#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
# include <iostream>

class	Cat : public Animal{
	private:	
		std::string _type;
	public:
		Cat(void);
		Cat(const Cat &Cat);
		~Cat(void);

		Cat &operator = (const Cat &cat);
		void	makeSound(void)const;
		std::string	getType(void)const;
};
#endif
