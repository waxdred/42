#include "Cat.hpp"

Cat::Cat(void): _type("WrongCat"){
	std::cout << "[Cat] Default constructor called" << std::endl;
	return ;
}

Cat::~Cat(void){
	std::cout << "[Cat] Destructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat &cat){
	std::cout << "[Cat] Copy constructor called" << std::endl;
	*this = cat;
	return;
}

Cat &Cat::operator = (const Cat &cat){
	if (&cat != this)
	{
		_type = cat._type;
	}
	return (*this);
}

void	Cat::makeSound(void)const{
	std::cout << _type << " Miaaaaaaaaaaaouuuuuuuu!!!!" << std::endl;
}

std::string	Cat::getType(void)const{
	return (_type);
}
