#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal"){
	std::cout << "[WrongAnimal] Default constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "[WrongAnimal] Destructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal){
	std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
	*this = animal;
	return;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &wrongAnimal){
	if (&wrongAnimal != this)
	{
		_type = wrongAnimal._type;
	}
	return (*this);
}

void WrongAnimal::makeSound(void){
	std::cout << _type << " grrrrrrrrrrrrrrrrrrrrrr!!!!" << std::endl;
}

std::string	WrongAnimal::getType(void)const{
	return (_type);
}

