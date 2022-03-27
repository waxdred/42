#include "rational.hpp"

/* Rational::Rational(void) : _num(0), _dnum(1){ */
/* } */

Rational::Rational(int num, int dnum)
{
	this->setNum(num);
	this->setDnum(dnum);
}

Rational::~Rational()
{
	std::cout << "Destructor" << std::endl;
}

int	Rational::getNum(void) const
{
	return (this->_num);	
}

int	Rational::getDnum(void) const
{
	return (this->_dnum);	
}

void	Rational::setNum(int num)
{
	this->_num = num;
}

void	Rational::setDnum(int dnum)
{
	if (dnum == 0)
	{
		std::cerr << "Error nb cannot be null" << std::endl;
		exit (-1);
	}
	this->_dnum = dnum;
}

// retur new os Rational for be print
std::ostream & operator << (std::ostream & os, const Rational & r)
{
	os << "[" << r.getNum() << "/" << r.getDnum() << "]";
	return (os);
}
