#include "Fixed.hpp"

Fixed::Fixed(void): _entier(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num){
	std::cout << "Int constructor called" << std::endl;
	_entier = num * pow(2, _fracBits);
	return ;
}

Fixed::Fixed(const float num): _entier(0){
	std::cout << "Float constructor called" << std::endl;
	_entier = round(num * pow(2, _fracBits));
	return ;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed &fixed){
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return;
}

int	Fixed::getRawBits(void)const{
	std::cout << "getRawBits member called" << std::endl;
	return (_entier);
}

void	Fixed::setRawBits(const int raw){
	std::cout << "setRawBits member called" << std::endl;
	_entier = raw;
}

Fixed	& Fixed::operator=(const Fixed &fixed){
	std::cout << "Copy assignement operator called" << std::endl;
	if (&fixed != this)
		_entier = fixed.getRawBits();
	return (*this);
}

float	Fixed::toFloat(void)const{
	return (_entier / pow(2, _fracBits));
}

int	Fixed::toInt(void)const{
	return (_entier / pow(2, _fracBits));
}

std::ostream & operator <<(std::ostream &o, Fixed const &fixed){
	o << fixed.toFloat();
	return (o);
}
