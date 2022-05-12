/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:40:13 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/11 21:13:22 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2022/05/11 20:24:28 by jmilhas           #+#    #+#             */
/*   updated: 2022/05/11 20:24:28 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iostream>
/**
* ------------------------ TODO ------------------------------- *
* ------------------------ FT_VECTOR_ITERATOR ----------------- *
* - Coplien form:
* [x](constructor):        Construct vector_iterator
* [x](destructor):         Vector_iterator destructor
* [x]operator=:            Assign content
*
* - Operators
* [ ]operators:            Operators for vector_iterator
* [ ]non-member operators: Operators for vector_iterator
* ------------------------------------------------------------- *
*/

namespace ft {
	template<typename T>
	class	vector_iterator{
		/* ------------------------------------------------------------- */
            	/* -------------------------- ALIASES -------------------------- */
		typedef std::ptrdiff_t 	difference_type;
		typedef T 		value_type;
		typedef value_type&	reference;
		typedef const value_type&	const_reference;
		typedef value_type*	pointer;
		typedef const value_type*	const_pointer;

		private:	
		  	pointer _ptr;
			
		public:
			vector_iterator(void): _ptr(0){};
			vector_iterator(pointer ptr): _ptr(ptr){};
			~vector_iterator(void){};
			vector_iterator& operator=(const vector_iterator& assign){
				if (this != &assign)
					_ptr = assign._ptr;
				return (*this);
			}
		/* ------------------------------------------------------------- */
            	/* --------------------- BOOL OPERATOR ------------------------- */

		bool operator ==(const vector_iterator &it)const{return (it._ptr == _ptr);}
		bool operator !=(const vector_iterator &it)const{return (it._ptr != _ptr);}
		bool operator <(const vector_iterator &it)const{return (it._ptr < _ptr);}
		bool operator >(const vector_iterator &it)const{return (it._ptr > _ptr);}
		bool operator <=(const vector_iterator &it)const{return (it._ptr <= _ptr);}
		bool operator >=(const vector_iterator &it)const{return (it._ptr >= _ptr);}

		/* ------------------------------------------------------------- */
            	/* --------------------- OPERATOR OVERLOAD --------------------- */
		vector_iterator operator ++(int){
			vector_iterator res(*this);
			++(*this);
			return (res);
		}
		vector_iterator operator --(int){
			vector_iterator res(*this);
			--(*this);
			return (res);
		}
	};
}
#endif
