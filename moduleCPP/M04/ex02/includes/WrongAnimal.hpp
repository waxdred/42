#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class	WrongAnimal{
	protected:	
		std::string _type;
		
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &WrongAnimal);
		~WrongAnimal(void);

		WrongAnimal &operator = (const WrongAnimal &wrongAnimal);
		void	makeSound(void);
		std::string	getType(void)const;
};
#endif
