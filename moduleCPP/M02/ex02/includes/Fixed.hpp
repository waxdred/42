#ifndef FIXED_HPP
# define FIXED_HPP

#include <algorithm>
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
		Fixed(const Fixed &fixed);
		~Fixed(void);

		Fixed &operator = (const Fixed &rhs);
		Fixed operator + (const Fixed &rhs)const;
		Fixed operator - (const Fixed &rhs)const;
		Fixed operator * (const Fixed &rhs)const;
		Fixed operator / (const Fixed &rhs)const;
		Fixed operator % (const Fixed &rhs)const;

		bool operator < (const Fixed &rhs);
		bool operator > (const Fixed &rhs);
		bool operator <= (const Fixed &rhs);
		bool operator >= (const Fixed &rhs);
		bool operator == (const Fixed &rhs);
		bool operator != (const Fixed &rhs);

		Fixed & operator++(void);
		Fixed operator++(int);
		Fixed & operator--(void);
		Fixed operator--(int);

		static Fixed const & max(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const & min(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream & operator <<(std::ostream &o, Fixed const &fixed);

#endif
