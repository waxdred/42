#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
	private:
		int			_entier;
		static const int	_fracBits = 8;
	public:
		Fixed(void);
		Fixed(const int);
		Fixed(const float);
		~Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed & operator = (const Fixed &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream & operator <<(std::ostream &o, Fixed const &fixed);

#endif
