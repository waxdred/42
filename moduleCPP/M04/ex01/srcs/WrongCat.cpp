#include "WrongCat.hpp"

WrongCat::WrongCat(void): _type("WrongCat"){
	std::cout << "[WrongCat] Default constructor called" << std::endl;
	return ;
}

WrongCat::~WrongCat(void){
	std::cout << "[WrongCat] Destructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &wrongCat){
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
	*this = wrongCat;
	return;
}

WrongCat &WrongCat::operator = (const WrongCat &wrongAnimal){
	if (&wrongAnimal != this)
	{
		_type = wrongAnimal._type;
	}
	return (*this);
}

void WrongCat::makeSound(void){
	std::cout << _type << " grrrrrrrrrrrrrrrrrrrrrr!!!!" << std::endl;
}

std::string	WrongCat::getType(void)const{
	return (_type);
}

