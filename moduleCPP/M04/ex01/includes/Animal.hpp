#ifndef ANIMAL
# define ANIMAL

# include <iostream>

class	Animal{
	protected:	
		std::string _type;
	public:
		Animal(void)const;
		Animal(const Animal &Animal);
		virtual ~Animal(void);

		Animal &operator = (const Animal &animal);
		virtual void	makeSound(void);
		std::string	getType(void)const;
};
	
#endif
