/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:47:38 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/27 13:42:39 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iostream>
/**
* ------------------------ TODO ------------------------------- *
* ------------------------ FT_VECTOR_ITERATOR ----------------- *
* - Coplien form:
* [x](constructor):        Construct iterator
* [x](destructor):         Vector_iterator destructor
* [x]operator=:            Assign content
*
* - Operators
* [x]operators:            Operators for iterator
* [x]non-member operators: Operators for iterator
* ------------------------------------------------------------- *
*/

#define ADD 0
#define SUB 1

namespace ft {
	template<typename T>
	class	iterator{
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
			iterator(void): _it(NULL){};
			iterator(value_type *it):_it(it) {}
			iterator(iterator const &copy) {*this = copy;}
			~iterator(void){};
			iterator& operator=(iterator const &assign){
				if (this != &assign)
					_it = assign._it;
				return (*this);
			}
			/* ------------------------------------------------------------- */
			/* --------------------- BOOL OPERATOR ------------------------- */

			bool operator ==(const iterator &it)const{return (it._it == _it);}
			bool operator !=(const iterator &it)const{return (it._it != _it);}
			bool operator <(const iterator &it)const{return (it._it > _it);}
			bool operator >(const iterator &it)const{return (it._it < _it);}
			bool operator <=(const iterator &it)const{return (it._it >= _it);}
			bool operator >=(const iterator &it)const{return (it._it <= _it);}

			/* ------------------------------------------------------------- */
			/* --------------------- OPERATOR OVERLOAD --------------------- */
			reference operator*() const{ return (*_it); }
			reference operator[](difference_type n) const{return (_it[n]);}
			pointer operator->() const{return(&(operator*()));}
			pointer base() const{return (_it);}
			iterator& operator++(void){ ++_it; return (*this); }
            		iterator& operator--(void){ --_it; return (*this); }

			iterator operator++(int)
            		{
                		iterator res(*this);
                		++(*this);
                		return (res);
            		}
            
            		iterator operator--(int)
            		{
                		iterator res(*this);
                		--(*this);
                		return (res);
            		}

			/**
            		*   Increments 1 time vector_iterator position.
            		*/
            		iterator& operator+=(difference_type nb){
            		    	movePtr(this->_it, nb, ADD);
            		    	return (*this);
            		}

            		/**
            		*   Increments nb times iterator position.
            		*/
            		iterator operator+(difference_type nb) const{
            		    	iterator it(*this);
            		    	
            		    	movePtr(it._it, nb, ADD);
            		    	return (it);
            		}
            		
            		/**
            		*   Decrements 1 time iterator position.
            		*/
            		iterator& operator-=(difference_type nb){
            		    	movePtr(this->_it, nb, SUB);
            		    	return (*this);
            		}

            		/**
            		*   Decrements nb times iterator position.
            		*/
            		iterator operator-(difference_type nb) const{
            		    	iterator it(*this);
            		    	
            		    	movePtr(it._it, nb, SUB);
            		    	return (it);
            		}

            		/**
            		*   @return     The range's lenght between this iterator and another one.
            		*/
            		difference_type operator-(iterator it) const{
            		    	return (this->_it - it._it);
            		}
            		

            		/* ------------------------------------------------------------- */
            		/* --------------- NON-MEMBER OPERATOR OVERLOADS --------------- */ 
            		
            		friend iterator operator+(difference_type nb, const iterator& it){
            		    	iterator newIt(it);
            		    	return (newIt += nb);
            		}

            		friend iterator operator-(difference_type nb, const iterator& it){
            		    	iterator newIt(it);
            		    	return (newIt -= nb);
            		}
            		/* ------------------------------------------------------------- */
            		/* ------------------ PRIVATE MEMBER FUNCTIONS ----------------- */

		private:

        	    	/**
        	    	*   Moves random_acces_iterator's pointer. Adapt between addition / substraction
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
        	    	    if (sign == ADD)
        	    	        mov = nb > 0 ? mov = 1: mov = -1;
        	    	    else
        	    	        mov = nb > 0 ? mov = -1: mov = 1;
                    	
        	    	    if (nb < 0)
        	    	        nb *= -1;
        	    	    for (; nb > 0; --nb)
        	    	        val += mov;
        	    	}

	};//class iterator
	  //// Non-member function overload of random access iterator
	template <class Iterator>
	bool operator==(const iterator<Iterator> &lhs, const iterator<Iterator> &rhs){
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(const iterator<Iterator> &lhs,
		const iterator<Iterator> &rhs){
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<(const iterator<Iterator> &lhs,
			const iterator<Iterator> &rhs){
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator<=(const iterator<Iterator> &lhs,
		const iterator<Iterator> &rhs){
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	bool operator>(const iterator<Iterator> &lhs,
		const iterator<Iterator> &rhs){
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator>=(const iterator<Iterator> &lhs,
		const iterator<Iterator> &rhs){
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	iterator<Iterator> operator+(
		typename iterator<Iterator>::difference_type n,
		const iterator<Iterator> &rev_it){
		return (iterator<Iterator>(rev_it.base() + n));
	}

	template <class Iterator>
	typename iterator<Iterator>::difference_type operator-( const iterator<Iterator> &lhs,
		const iterator<Iterator> &rhs){
		return (lhs.base() - rhs.base());
	}

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
