#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
class Rational
{
	private:
		int	_num;
		int	_dnum;
	public:
		//constructor
		/* Rational(); */
		//supercharge constructor
		Rational(int num = 0, int dnum = 1);
		// destructor
		~Rational();

		// getter / setter
		int 	getNum(void) const;
		int 	getDnum(void) const;
		void	setNum(int num);
		void	setDnum(int dnum);
};
// add constructor for be print
std::ostream & operator << ( std::ostream & os, const Rational & r);
#endif
