#ifndef ANIMAL
# define ANIMAL

# include <iostream>

class	Animal{
	protected:	
		std::string _type;
	public:
		Animal(void);
		Animal(const Animal &Animal);
		virtual ~Animal(void);

		Animal &operator = (const Animal &animal);
		virtual void	makeSound(void)const = 0;
		std::string	getType(void)const;
};
	
#endif
