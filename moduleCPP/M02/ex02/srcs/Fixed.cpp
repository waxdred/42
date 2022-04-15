#include "Fixed.hpp"

Fixed::Fixed(void): _entier(0){
	/* std::cout << "Default constructor called" << std::endl; */
	return ;
}

Fixed::~Fixed(void){
	/* std::cout << "Destructor called" << std::endl; */
	return ;
}

Fixed::Fixed(const Fixed &fixed){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = fixed;
	return;
}

Fixed::Fixed(const int num){
	/* std::cout << "Int constructor called" << std::endl; */
	_entier = num * pow(2, _fracBits);
	return ;
}

Fixed::Fixed(const float num): _entier(0){
	/* std::cout << "Float constructor called" << std::endl; */
	_entier = round(num * pow(2, _fracBits));
	return ;
}

int	Fixed::getRawBits(void)const{
	/* std::cout << "getRawBits member called" << std::endl; */
	return (_entier);
}

void	Fixed::setRawBits(const int raw){
	/* std::cout << "setRawBits member called" << std::endl; */
	_entier = raw;
}

float	Fixed::toFloat(void)const{
	return (_entier / pow(2, _fracBits));
}

int	Fixed::toInt(void)const{
	return (_entier / pow(2, _fracBits));
}

Fixed	&Fixed::operator=(const Fixed &rhs){
	if (&rhs != this)
		_entier = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &rhs)const{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs)const{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs)const{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs)const{
	return (this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator%(const Fixed &rhs)const{
	return (this->toInt() % rhs.toInt());
}

bool	Fixed::operator<(const Fixed &rhs){
	return (_entier < rhs.getRawBits());
}

bool	Fixed::operator>(const Fixed &rhs){
	return (_entier > rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs){
	return (_entier <= rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs){
	return (_entier >= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs){
	return (_entier == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs){
	return (_entier != rhs.getRawBits());
}

Fixed	&Fixed::operator++(void){
	_entier++;
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed	Fixed::operator--(int){
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed	&Fixed::operator--(void){
	_entier--;
	return (*this);
}

Fixed const & Fixed::max (const Fixed &a, const Fixed &b){
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b){
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed const & Fixed::min(const Fixed &a, const Fixed &b){
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed & Fixed::min(Fixed &a, Fixed &b){
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

std::ostream & operator <<(std::ostream &o, Fixed const &fixed){
	o << fixed.toFloat();
	return (o);
}
