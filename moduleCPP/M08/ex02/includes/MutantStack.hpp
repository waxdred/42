/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:21:00 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/18 10:40:29 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>


template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack& copy) : std::stack<T>(copy){};
		~MutantStack() {};
		MutantStack<T>& operator=(const MutantStack<T>& ref)
		{
			if (*this == ref)
				return (*this);
			std::stack<T>::operator=(ref);
			return (*this);
		};
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { 
			return (std::stack<T>::c.begin()); 
		};
		iterator end() { 
			return (std::stack<T>::c.end()); 
		};
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { 
			return (std::stack<T>::c.rbegin()); 
		};
		reverse_iterator rend() { 
			return (std::stack<T>::c.rend()); 
		};
};
#endif
