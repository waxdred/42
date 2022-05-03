/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:39:37 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/03 08:39:46 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <deque>
# include <stack>

/* https://stackoverflow.com/questions/11275444/c-template-typename-iterator */

template<typename T>
class	MutantStack : public std::stack<T>{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &mutant);
		~MutantStack(void);

		MutantStack<T> &operator = (const MutantStack &mutant);

	
		typedef typename std::deque<T>::iterator iterator;
		iterator begin(){
			return (this->c.begin());
		}
		iterator end(){
			return (this->c.end());
		}
};
#endif
