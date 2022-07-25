/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_vector_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:49:26 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/25 13:56:02 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef filename
# define filename

# include <iostream>
/**
	| ------------------------ TODO ------------------------------- *
	| ------------------------ FT_VECTOR_ITERATOR ----------------- *
	| - Coplien form:
	| [x](constructor):        Construct vector_iterator
	| [x](destructor):         Vector_iterator destructor
	| [x]operator=:            Assign content
	|
	| - Operators
	| [x]operators:            Operators for vector_iterator
	| [x]non-member operators: Operators for vector_iterator
	| ------------------------------------------------------------- *
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
		  	pointer _it;
			
		public:
			reverse_iterator(void): _it(NULL){};

			reverse_iterator(value_type *it):_it(it) {}

			reverse_iterator(reverse_iterator const &copy) {*this = copy;}

			~reverse_iterator(void){};

			reverse_iterator& operator=(reverse_iterator const &assign){
				if (this != &assign)
					_it = assign._it;
				return (*this);
			}
			/* ------------------------------------------------------------- */
			/* --------------------- BOOL OPERATOR ------------------------- */

			bool operator ==(const reverse_iterator &it)const{return (it._it == _it);}
			bool operator !=(const reverse_iterator &it)const{return (it._it != _it);}
			bool operator <(const reverse_iterator &it)const{return (it._it > _it);}
			bool operator >(const reverse_iterator &it)const{return (it._it < _it);}
			bool operator <=(const reverse_iterator &it)const{return (it._it >= _it);}
			bool operator >=(const reverse_iterator &it)const{return (it._it <= _it);}

			/* ------------------------------------------------------------- */
			/* --------------------- OPERATOR OVERLOAD --------------------- */
			reference operator*() const{ return (*_it); }
			reference operator[](difference_type n) const{return (_it[n]);}
			pointer operator->() const{return(&(operator*()));}
			pointer base() const{return (_it);}
			reverse_iterator& operator++(void){ --_it; return (*this); }
            		reverse_iterator& operator--(void){ ++_it; return (*this); }

			reverse_iterator operator++(int)
            		{
                		reverse_iterator res(*this);
                		++(*this);
                		return (res);
            		}
            
            		reverse_iterator operator--(int)
            		{
                		reverse_iterator res(*this);
                		--(*this);
                		return (res);
            		}

			/**
            		*   Increments 1 time vector_reverse_iterator position.
            		*/
            		reverse_iterator& operator+=(difference_type nb){
            		    	movePtr(this->_it, nb, SUB);
            		    	return (*this);
            		}

            		/**
            		*   Increments nb times reverse_iterator position.
            		*/
            		reverse_iterator operator+(difference_type nb) const{
            		    	reverse_iterator it(*this);
            		    	
            		    	movePtr(it._it, nb, SUB);
            		    	return (it);
            		}
            		
            		/**
            		*   Decrements 1 time reverse_iterator position.
            		*/
            		reverse_iterator& operator-=(difference_type nb){
            		    	movePtr(this->_it, nb, ADD);
            		    	return (*this);
            		}

            		/**
            		*   Decrements nb times reverse_iterator position.
            		*/
            		reverse_iterator operator-(difference_type nb) const{
            		    	reverse_iterator it(*this);
            		    	
            		    	movePtr(it._it, nb, ADD);
            		    	return (it);
            		}

            		/**
            		*   @return     The range's lenght between this reverse_iterator and another one.
            		*/
            		difference_type operator-(reverse_iterator it) const{
            		    	return (this->_it - it._it);
            		}
            		

            		/* ------------------------------------------------------------- */
            		/* --------------- NON-MEMBER OPERATOR OVERLOADS --------------- */ 
            		
            		friend reverse_iterator operator+(difference_type nb, const reverse_iterator& it){
            		    	reverse_iterator newIt(it);
            		    	return (newIt += nb);
            		}

            		friend reverse_iterator operator-(difference_type nb, const reverse_iterator& it){
            		    	reverse_iterator newIt(it);
            		    	return (newIt -= nb);
            		}
            		/* ------------------------------------------------------------- */
            		/* ------------------ PRIVATE MEMBER FUNCTIONS ----------------- */

		private:

        	    	/**
        	    	*   Moves random_acces_reverse_iterator's pointer. Adapt between addition / substraction
        	    	*   operation. 
        	    	*
        	    	*   @param val  The pointer to move.
        	    	*   @param nb   Number of time the pointer will be increased / decreased.
        	    	*   @param sign Indicate if it's an addition or a substraction.
        	    	*/
        	    	void movePtr(pointer& val, long nb, bool sign) const
        	    	{
        	    	    int mov;
                    	
        	    	    // If addtion, mov will be positive. If substraction, negative.
        	    	    if (sign == SUB)
        	    	        mov = nb > 0 ? mov = 1: mov = -1;
        	    	    else
        	    	        mov = nb > 0 ? mov = -1: mov = 1;
                    	
        	    	    if (nb < 0)
        	    	        nb *= -1;
        	    	    for (; nb > 0; --nb)
        	    	        val += mov;
        	    	}
	};// class reverse_reverse_iterator 
}//namespace
#endif
