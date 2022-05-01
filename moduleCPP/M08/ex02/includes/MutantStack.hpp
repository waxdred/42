/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:39:37 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 19:55:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
#include <iterator>
# include <stack>

/* https://stackoverflow.com/questions/11275444/c-template-typename-iterator */

template<typename T>
class	MutantStack : public std::stack<T>{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &mutant);
		~MutantStack(void);

		MutantStack<T> operator = (const MutantStack &mutant);

		/* typedef typename MutantStack<T>::stack::iterator iterator; */
		/* iterator begin(); */
		/* iterator end(); */

};
#endif
