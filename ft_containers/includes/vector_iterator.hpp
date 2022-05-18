/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:34:49 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/18 15:27:37 by jmilhas          ###   ########.fr       */
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

#define ADD 0
#define SUB 1

namespace ft {
	template<typename T>
	class	vector_iterator{
		/* ------------------------------------------------------------- */
            	/* -------------------------- ALIASES -------------------------- */
		typedef std::ptrdiff_t 		difference_type;
		typedef T 			value_type;
		typedef T* 			elemPtr;
		typedef value_type&		reference;
		typedef const value_type&	const_reference;
		typedef value_type*		pointer;
		typedef const value_type*	const_pointer;

		private:	
		  	elemPtr _ptr;
			
		public:
			vector_iterator(void): _ptr(0){};
			vector_iterator(const vector_iterator &copy) { _ptr = copy.get_ptr(); }
			~vector_iterator(void){};
			vector_iterator& operator=(const vector_iterator& assign){
				if (this != &assign)
					_ptr = assign._ptr;
				return (*this);
			}

		vector_iterator get_ptr(void){
			return (this->_ptr);
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
		reference operator*() const{ return (_ptr); }

		/* Incrementate iterator n pos*/
		vector_iterator &operator+=(int n){
			this->move_ptr(this->_ptr, n, ADD);
			return (*this);
		}

		/* Incrementate iterator n pos */
		vector_iterator &operator+(int n){
			this->move_ptr(this->_ptr, n, ADD);
			return (*this);
		}
		/* Incrementate iterator ++*/
		vector_iterator &operator++(int){
			this->move_ptr(this->*_ptr, 1, ADD);
			return (*this);
		}

		/* Decrementate iterator n pos*/
		vector_iterator &operator-=(int n){
			this->move_ptr(this->_ptr, n, SUB);
			return (*this);
		}
		/* Decrementate iterator n pos*/
		vector_iterator &operator-(int n){
			this->move_ptr(this->_ptr, n, SUB);
			return (*this);
		}
		/* Decrementate iterator --*/
		vector_iterator &operator--(int){
			this->move_ptr(this->_ptr, 1, SUB);
			return (*this);
		}
		private:
			void move_ptr(elemPtr &elem, size_t n, bool sign){
				int mov;

				if (!sign)
					mov = n > 0 ? mov = 1 : mov = -1;
				else 
					mov = n > 0 ? mov = -1 : mov = 1;
				if (n < 0)
					n *= -1;
				for (; n > 0; n--)
					elem += mov;
			}

	};
}
#endif
