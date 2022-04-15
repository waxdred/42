#include "Fixed.hpp"

int main(void)
{
	Fixed 	a(5);
	Fixed	b(a);
	Fixed	c;

	c = b;
	b = c;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
