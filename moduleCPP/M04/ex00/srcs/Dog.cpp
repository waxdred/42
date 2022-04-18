#include "Dog.hpp"

Dog::Dog(void): _type("Dog"){
	std::cout << "[Dog] Default constructor called" << std::endl;
	return ;
}

Dog::~Dog(void){
	std::cout << "[Dog] Destructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &dog){
	std::cout << "[Dog] Copy constructor called" << std::endl;
	*this = dog;
	return;
}

Dog &Dog::operator = (const Dog &dog){
	if (&dog != this)
	{
		_type = dog._type;
	}
	return (*this);
}

void Dog::makeSound(void)const{
	std::cout << _type << " Whafffffffffffff" << std::endl;
}

std::string	Dog::getType(void)const{
	return (_type);
}
