/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:52:48 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/27 15:21:18 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include "vector.hpp"

 /**
    * ------------------------------------------------------------- *
    * ------------------------ FT::STACK -------------------------- *
    *
    * - Coplien form:
    * [x](constructor):        Construct stack
    * [x](destructor):         Destruct stack
    * [x]operator=:            Assign content
    *
    * - Member functions:
    * [x]empty:                Test whether container is empty
    * [x]size:                 Return size
    * [x]top:                  Access next element
    * [x]push:                 Insert element
    * [x]pop:                  Remove top element
    * [x]swap:		       swap element
    *
    * - Non-member function overloads:
    * [x]relational operators: Relational operators for stack
    * [x]operator==
    * [x]operator!=
    * [x]operator<
    * [x]operator<=
    * [x]operator>
    * [x]operator>=
    * ------------------------------------------------------------- *
    */

namespace ft{
	template <class T, class Container = ft::vector<T> >
	class stack{
    		/* ------------------------------------------------------------- */
    		/* ------------------------ ALLIAS ----------------------------- */
		public:
			typedef T		value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type		c;
		public:
    		/* ------------------------------------------------------------- */
    		/* ------------------------ CONSTRUCTOR ------------------------ */

			/* @Brief default constructor */
			/* @Param Container ft::vector */
			explicit stack (const container_type& ctnr = container_type()): c(ctnr){};

			/* @brief Copy constructor */
			/* @param const stack */
			stack(const stack &st){
				this->_swap(this->c, st.c);
				return (*this);
			};

			/* @brief destructor */
			~stack(void){};

    		/* ------------------------------------------------------------- */
    		/* ------------------------ MEMBER FUNCTION  ------------------- */

			/* @brief Test whether container is empty */
			/* @return true if the underlying container's size is 0, false otherwise. */
			bool empty() const{return(this->c.empty());};

			/* @brief Return size */  
			/* @return The number of elements in the underlying container. */
			size_type size() const{return (this->c.size());};

			/* @brief Access next element */
			/* @return A reference to the top element in the stack. */
			value_type& top(){return (this->c.back());};

			/* @brief const Access next element*/
			/* @return A reference to the top element in the stack. */
			const value_type& top() const{return (this->c.back());};

			/* @brief Insert element */
			/* @param Value to Insert */
			void push (const value_type& val){this->c.push_back(val);};

			/* @brief Remove top element */
			void pop(){this->c.pop_back();};
			
			/* @brief Swap content */
			/* @param Another stack */
			void swap (stack& x){
				this->_swap(this->c, x.c);
			}

		private:
    		/* ------------------------------------------------------------- */
    		/* ---------------------- NON MEMBER FUNCTION------------------- */
			/* use friend car nous ne pouvons pas accéder aux attributs de la classe externe */
             		/* Une fonction firend est une fonction qui peut accéder aux membres privés d'une classe comme si elle était membre */

			template <class A, class B>
  			friend bool operator== (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
  			friend bool operator!= (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
  			friend bool operator<  (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
  			friend bool operator<= (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
  			friend bool operator>  (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
  			friend bool operator>= (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <typename U>
			void _swap(U &a, U &b){
				U tmp(a);
				a = b;
				b = tmp;
			}



	};//stack
	template <class T, class Container>
  	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.c == rhs.c);
	}
	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.c != rhs.c);
	}
	template <class T, class Container>
  	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.c < rhs.c);
	}
	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.c <= rhs.c);
	}
	template <class T, class Container>
  	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.c > rhs.c);
	}
	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.c >= rhs.c);
	}
}//namespace
#endif
