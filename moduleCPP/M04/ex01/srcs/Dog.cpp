#include "Dog.hpp"

Dog::Dog(void){
	std::cout << "[Dog] Default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	return ;
}

Dog::~Dog(void){
	std::cout << "[Dog] Destructor called" << std::endl;
	delete this->_brain;
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
		this->_type = dog._type;
		*(this)->_brain = *(dog)._brain;
	}
	return (*this);
}

void Dog::makeSound(void)const{
	std::cout << _type << " Whafffffffffffff" << std::endl;
}

std::string	Dog::getType(void)const{
	return (_type);
}
