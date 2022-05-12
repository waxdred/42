/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:46 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/11 22:24:02 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>
# include "vector_iterator.hpp"
/**
    * ------------------------ TODO ------------------------------- *
    * ------------------------ FT::VECTOR ------------------------- *
    *
    * - Coplien form:
    * [x](constructor):        Construct vector
    * [x](destructor):         Destruct vector
    * [x]operator=:            Assign vector
    *
    * - Iterators:
    * [x]begin:                Return iterator to beginning
    * [x]end:                  Return iterator to end
    * [ ]rbegin:               Return reverse iterator to reverse beginning
    * [ ]rend:                 Return reverse iterator to reverse end
    *
    * - Capacity:
    * [ ]size:                 Return size
    * [ ]max_size:             Return maximum size
    * [ ]resize:               Change size
    * [ ]capacity:             Return size of allocated storage capacity
    * [ ]empty:                Test whether vector is empty
    * [ ]reserve:              Request a change in capacity
    * [ ]
    * - Element access:
    * [ ]operator[]:           Access element
    * [ ]at:                   Access element
    * [ ]front:                Access first element
    * [ ]back:                 Access last element
    * [ ]
    * - Modifiers:
    * [ ]assign:               Assign vector content
    * [ ]push_back:            Add element at the end
    * [ ]pop_back:             Delete last element
    * [ ]insert:               Insert elements
    * [ ]erase:                Erase elements
    * [ ]swap:                 Swap content
    * [ ]clear:                Clear content
    * 
    * - Non-member function overloads:
    * [ ]relational operators: Relational operators for vector
    * [ ]swap:                 Exchange contents of two vectors
    * ------------------------------------------------------------- *
    */

namespace ft{
	template<typename T, class Allocator = std::allocator<T> >
  	class	vector {
    			/*-------------------------------------------------------------*/
    			/*-----------------------ALLIAS--------------------------------*/
			typedef T 					value_type;
			typedef Allocator 				allocator_type;
			typedef typename std::ptrdiff_t 		difference_type;
			typedef typename std::size_t 			size_type;
			typedef typename Allocator::reference 		reference;
			typedef typename Allocator::const_reference 	const_reference;
			typedef typename Allocator::pointer 		pointer;
			typedef typename Allocator::const_pointer 	const_pointer;
			typedef typename ft::vector_iterator<T>      	iterator;
            		typedef typename ft::vector_iterator<T>       	const_iterator;


		private:
			Allocator 	_alloc;
			T 		*_ptr;
			size_type	_size_alloc;
			size_type	_capacity;
		public:
			/* @Brief Default consturctor,*/
			/* Create a vector with a size at 0*/
			/* @Param  alloc T*/
			explicit vector(const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _size_alloc(0), _capacity(0){
				this->_ptr = _alloc.allocate(_capacity);};
			
			/* @Brief Fill constructor, */
			/* creates a vector with a size of n and initializes the values*/ 
			/* @param n        The number of elements that will be created. */
			/* @param val      The value used for initialization (value initialized by default). */
			/* @param alloc    The template param used for the allocation. */
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _size_alloc(n), _capacity(n){
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_ptr + i, val);
				};
			
			 /* @Brief Range constructor, creates a vector with a size equal to the range between two */
			 /* iterators and copy the values of this range to the new elements created. */
			
			 /* @param first    An iterator representing first element of the range. */
			 /* @param last     An iterator indicating end of the range (will be excluded and not copied). */
			 /* @param alloc    The template param used for the allocation. */
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _ptr(0), _size_alloc(0), _capacity(0){
				while (first != last){
					this->push_back(*first);
					first++;
				}
			};
			
			/* @Brief Copy constructor, creates a vector with the same size and copy/construct */
			/* all x values to the new area allocated. */
			/* @param x        The vector that will be copied. */
			vector(const vector& x)
				: _alloc(allocator_type()), _ptr(0), _size_alloc(0), _capacity(0){
				*this = x;
			};
			
			/* @Brief Destructor, destroys all the vector's elements and then deallocates vector's */
			/* ressources. */
			~vector(){
				/* this->clear(); */
				if (this->_size_alloc > 0){
					this->_alloc.deallocate(_ptr, _size_alloc);
					this->_size_alloc = 0;
					this->_capacity = 0;
				}
			};
			
			 /* @Brief Assigns a vector to this vector. Calls the copy constructor to do the */
			 /* assignment(copy and swap idiom). */
			 /* @param x        The vector that will be assigned. */
			 vector& operator= (const vector& x)
			 {
			     vector tmp(x);
			     swap(tmp);
			     return *this;
			 }
			
			 /* ------------------------------------------------------------- */
			 /* ------------------------- ITERATORS ------------------------- */
			 iterator	begin(void){return (iterator(_ptr));}
			 const_iterator	begin(void)const {return (const_iterator(_ptr));}
			 iterator	end(void){return (iterator(_ptr + _size_alloc));}
			 const_iterator	end(void)const {return (const_iterator(_ptr + _size_alloc));}
			
			 /* ------------------------------------------------------------- */
			 /* -------------------------- CAPACITY ------------------------- */
			 size_type	size() const { return (_capacity); };
			 /* ------------------------------------------------------------- */
            		 /* ---------------------- ELEMENTS ACCESS ---------------------- */ 
			 
			 /* ------------------------------------------------------------- */
            		 /* ------------------------- MODIFIERS ------------------------- */
			 void push_back (const value_type val){
				 if (this->_size_alloc + 1 > this->_capacity)
					 return;
				 _alloc.construct(&_ptr[_size_alloc++], val);
				 vector<T, T>(djaz, InputIterator last)
			 }
};
template < class T >
std::ostream& operator <<(std::ostream& s, ft::vector<T>& v) 
{
	/* if (v.empty() == true) */
	/* 	return (s); */
	s << "{";
	for (typename vector<T>::iterator it = v.begin(); it + 1 != v.end(); ++it)
	{
		s << *it << ", ";
	}
	s << v[v.size() - 1] << "}";
	return s;
}
}
#endif
