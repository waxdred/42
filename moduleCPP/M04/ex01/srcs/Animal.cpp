#include "Animal.hpp"

Animal::Animal(void): _type("Animal"){
	std::cout << "[Animal] Default constructor called" << std::endl;
	return ;
}

Animal::~Animal(void){
	std::cout << "[Animal] Destructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal &animal){
	std::cout << "[Animal] Copy constructor called" << std::endl;
	*this = animal;
	return;
}

Animal &Animal::operator = (const Animal &animal){
	if (&animal != this)
	{
		_type = animal._type;
	}
	return (*this);
}

void Animal::makeSound(void){
	std::cout << _type << " grrrrrrrrrrrrrrrrrrrrrr!!!!" << std::endl;
}

std::string	Animal::getType(void)const{
	return (_type);
}
