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
		typedef value_type&		reference;
		typedef const value_type&	const_reference;
		typedef value_type*		pointer;
		typedef const value_type*	const_pointer;

		private:	
		  	value_type *_ptr;
			
		public:
			vector_iterator(void): _ptr(0){};
			vector_iterator(value_type *ptr = 0):_ptr(ptr) {}
			vector_iterator(const vector_iterator &copy) {
				_ptr = copy._ptr;
			}
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
			reference operator*() const{ return (*_ptr); }

			/* Incrementate iterator n pos*/
			vector_iterator &operator+=(int n){
				this->move_ptr(this->_ptr, n, ADD);
				return (*this);
			}

			/* Incrementate iterator n pos */
			vector_iterator operator+(int n){
				vector_iterator it(*this);
				this->move_ptr(it._ptr, n, ADD);
				return (it);
			}
			/* Incrementate iterator ++*/
			vector_iterator &operator++(int){
				/* this->move_ptr(this->_ptr, 1, ADD); */
				this->_ptr++;
				return (*this);
			}

			/* Decrementate iterator n pos*/
			vector_iterator &operator-=(int n){
				this->move_ptr(this->_ptr, n, SUB);
				return (*this);
			}
			/* Decrementate iterator n pos*/
			vector_iterator operator-(int n)const{
				vector_iterator it(*this);
				this->move_ptr(it._ptr, n, SUB);
				return (it);
			}
			/* Decrementate iterator --*/
			vector_iterator &operator--(int){
				this->_ptr--;
				/* this->move_ptr(this->_ptr, 1, SUB); */
				return (*this);
			}
			
			size_t operator-(vector_iterator it) const
            		{
                		return (this->_ptr - it._ptr);
            		}
			
			size_t operator+(vector_iterator it) const
            		{
                		return (this->_ptr + it._ptr);
            		}

			friend vector_iterator operator+(const vector_iterator& it, int nb)
        	        {
        	            	vector_iterator newIt(it);
        	            	return (newIt += nb);
        	        }
        	    
        	        friend vector_iterator operator-(const vector_iterator& it, int nb)
        	        {
        	            	vector_iterator newIt(it);
        	            	return (newIt -= nb);
        	        }


		private:
			void move_ptr(T *elem, size_t n, bool sign){
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

	};//class
	template <class InputIterator>
	size_t lenght_it(InputIterator &first, InputIterator &last){
		size_t ret = 0;

		while (first != last){
			first++;
			ret++;
		}
		return (ret);
	}
}//namespace
#endif
