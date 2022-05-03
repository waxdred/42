/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:26:31 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 18:41:53 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stack>

template<typename T>
class	Vector : std::stack<T>{
	private:	
		
	public:
		template<typename T>
		Vector(void): Vector::stack<T>(){};
		Vector(const Vector &Vector);
		~Vector(void);

		Vector &operator = (const Vector &vector);
};
#endif
