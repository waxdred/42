#include "Fixed.hpp"

Fixed::Fixed(void): _entier(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int a): _entier(a){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return;
}

int Fixed::getRawBits(void)const{
	std::cout << "getRawBits member called" << std::endl;
	return (_entier);
}

void Fixed::setRawBits(const int raw){
	std::cout << "setRawBits member called" << std::endl;
	_entier = raw;
}

Fixed & Fixed::operator=(const Fixed &fixed){
	std::cout << "Copy assignement operator called" << std::endl;
	if (&fixed != this)
		_entier = fixed.getRawBits();
	return (*this);
}
