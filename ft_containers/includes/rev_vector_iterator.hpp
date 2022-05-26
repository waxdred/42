/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_vector_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:49:26 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 15:28:36 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef filename
# define filename

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

namespace ft{
	template<typename T>
	class reverse_iterator{
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
			reverse_iterator(void): _ptr(0){};
			reverse_iterator(value_type *ptr = 0):_ptr(ptr) {}
			reverse_iterator(const reverse_iterator &copy) {
				_ptr = copy._ptr;
			}
			~reverse_iterator(void){};
			reverse_iterator& operator=(const reverse_iterator& assign){
				if (this != &assign)
					_ptr = assign._ptr;
				return (*this);
			}

			/* ------------------------------------------------------------- */
			/* --------------------- BOOL OPERATOR ------------------------- */
			bool operator ==(const reverse_iterator &it)const{return (it._ptr == _ptr);}
			bool operator !=(const reverse_iterator &it)const{return (it._ptr != _ptr);}
			bool operator <(const reverse_iterator &it)const{return (it._ptr < _ptr);}
			bool operator >(const reverse_iterator &it)const{return (it._ptr > _ptr);}
			bool operator <=(const reverse_iterator &it)const{return (it._ptr <= _ptr);}
			bool operator >=(const reverse_iterator &it)const{return (it._ptr >= _ptr);}


			/* ------------------------------------------------------------- */
			/* --------------------- OPERATOR OVERLOAD --------------------- */
			reference operator*() const{ return (*_ptr); }

			/* Incrementate iterator n pos*/
			reverse_iterator &operator+=(int n){
				this->move_ptr(this->_ptr, n, SUB);
				return (*this);
			}

			/* Incrementate iterator n pos */
			reverse_iterator operator+(int n){
				reverse_iterator it(*this);
				this->move_ptr(it._ptr, n, SUB);
				return (it);
			}
			/* Incrementate iterator ++*/
			reverse_iterator &operator++(int){
				/* this->move_ptr(this->_ptr, 1, ADD); */
				this->_ptr--;
				return (*this);
			}

			/* Decrementate iterator n pos*/
			reverse_iterator &operator-=(int n){
				this->move_ptr(this->_ptr, n, ADD);
				return (*this);
			}
			/* Decrementate iterator n pos*/
			reverse_iterator operator-(int n)const{
				reverse_iterator it(*this);
				this->move_ptr(it._ptr, n, ADD);
				return (it);
			}
			/* Decrementate iterator --*/
			reverse_iterator &operator--(int){
				this->_ptr++;
				/* this->move_ptr(this->_ptr, 1, SUB); */
				return (*this);
			}
			
			size_t operator-(reverse_iterator it) const
            		{
                		return (this->_ptr + it._ptr);
            		}
			
			size_t operator+(reverse_iterator it) const
            		{
                		return (this->_ptr - it._ptr);
            		}

			friend reverse_iterator operator+(const reverse_iterator& it, int nb)
        	        {
        	            	reverse_iterator newIt(it);
        	            	return (newIt -= nb);
        	        }
        	    
        	        friend reverse_iterator operator-(const reverse_iterator& it, int nb)
        	        {
        	            	reverse_iterator newIt(it);
        	            	return (newIt += nb);
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

		

	};// class 
}//namespace
#endif
