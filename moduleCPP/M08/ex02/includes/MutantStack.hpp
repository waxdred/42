/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:39:37 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/02 22:23:33 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>
# include <queue>

/* https://stackoverflow.com/questions/11275444/c-template-typename-iterator */

template<typename T>
class	MutantStack : public std::stack<T>{
	public:
		typedef typename std::queue<T>::iterator iterator;
		MutantStack(void);
		MutantStack(const MutantStack &mutant);
		virtual ~MutantStack(void);

		MutantStack<T> operator = (const MutantStack &mutant);

		iterator begin(){
			return (this->c.begin());
		};
		iterator end(){
			return (this->c.end());
		};

};
#endif
