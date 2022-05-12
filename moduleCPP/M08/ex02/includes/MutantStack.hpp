/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:39:37 by jmilhas           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/02 22:23:33 by jmilhas          ###   ########.fr       */
=======
/*   Updated: 2022/05/03 08:39:46 by jmilhas          ###   ########.fr       */
>>>>>>> c9fe9fd36452ce99e4d3adc89730062c3a9983ee
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
<<<<<<< HEAD
=======
# include <deque>
>>>>>>> c9fe9fd36452ce99e4d3adc89730062c3a9983ee
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

<<<<<<< HEAD
		MutantStack<T> operator = (const MutantStack &mutant);

		iterator begin(){
			return (this->c.begin());
		};
		iterator end(){
			return (this->c.end());
		};
=======
		MutantStack<T> &operator = (const MutantStack &mutant);
>>>>>>> c9fe9fd36452ce99e4d3adc89730062c3a9983ee

	
		typedef typename std::deque<T>::iterator iterator;
		iterator begin(){
			return (this->c.begin());
		}
		iterator end(){
			return (this->c.end());
		}
};
#endif
