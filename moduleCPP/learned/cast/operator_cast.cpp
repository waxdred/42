/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_cast.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:13:25 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 09:23:21 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Foo{
	private:
		float _v;
	public:
		Foo(const float v): _v(v){};
		float getV(void)const {
			return (this->_v);
		}
		operator float(){
			return (this->_v);
		}
		operator int(){
			return (static_cast<int>(this->_v));
		}
};

int main(void)
{
	Foo	a(42.24515f);
	float	b = a;
	int	c = a;

	std::cout << "Foo " << a.getV() << std::endl;
	std::cout << "Float " << b << std::endl;
	std::cout << "int " << c << std::endl;
	std::cout << "operator dans une class permet de regarder si on veux faire un cast\n\
		\texemple:\n\
		\t\t	Foo	a(42.24515f)\n\
		\t\t	float	b = a;\n\
		\t\t	int	c = a;\n\
		via la fonction operator dans la class Foo on n'a pas besoin de faire le cast'" << std::endl;
	return 0;
}
