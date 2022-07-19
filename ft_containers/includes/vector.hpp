/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:46 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/18 23:39:58 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
#include <strings.h>
# include "vector_iterator.hpp"
# include "rev_vector_iterator.hpp"
# include "tools.hpp"
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
    * [x]rbegin:               Return reverse iterator to reverse beginning
    * [x]rend:                 Return reverse iterator to reverse end
    *
    * - Capacity:
    * [x]size:                 Return size
    * [x]max_size:             Return maximum size
    * [x]resize:               Change size
    * [x]capacity:             Return size of allocated storage capacity
    * [x]empty:                Test whether vector is empty
    * [x]reserve:              Request a change in capacity
    *
    * - Element access:
    * [x]operator[]:           Access element
    * [x]at:                   Access element
    * [x]front:                Access first element
    * [x]back:                 Access last element
    *
    * - Modifiers:
    * [x]assign:               Assign vector content
    * [x]push_back:            Add element at the end
    * [x]pop_back:             Delete last element
    * [ ]insert:               Insert elements
    * [x]erase:                Erase elements
    * [x]swap:                 Swap content
    * [x]clear:                Clear content
    * 
    * - Non-member function overloads:
    * [x]relational operators: Relational operators for vector
    * [x]swap:                 Exchange contents of two vectors
    *
    * - Allocator:
    * [ ] get_allocator:       Get allocator
    * ------------------------------------------------------------- *
    */

namespace ft{
	template<typename T, class Allocator = std::allocator<T> >
  	class	vector {
		public:
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
			typedef typename ft::iterator<T>      		iterator;
            		typedef typename ft::iterator<T>       		const_iterator;
			typedef typename ft::reverse_iterator<T>      	rev_iterator;
            		typedef typename ft::reverse_iterator<T>       	rev_const_iterator;


		private:
			allocator_type 	_alloc; 
			value_type	*_ptr;
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
					this->_ptr = _alloc.allocate(_capacity);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_ptr + i, val);
				};
			
			 /* @Brief Range constructor, creates a vector with a size equal to the range between two */
			 /* iterators and copy the values of this range to the new elements created. */
			 /* @param first    An iterator representing first element of the range. */
			 /* @param last     An iterator indicating end of the range (will be excluded and not copied). */
			 /* @param alloc    The template param used for the allocation. */
			 template <class InputIterator>
            		 vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                    		typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) :_alloc(alloc){
				 size_type size = last - first;
				 this->_ptr = _alloc.allocate(size);
				 for (size_type i = 0; first != last; first++, i++){
					_alloc.construct(_ptr + i, *first);
				 }
				 this->_capacity = size;
				 this->_size_alloc = size;
			};
			
			/* @Brief Copy constructor, creates a vector with the same size and copy/construct */
			/* all x values to the new area allocated. */
			/* @param x        The vector that will be copied. */
			vector(const vector& x)
				: _alloc(x._alloc), _size_alloc(x._size_alloc), _capacity(x._capacity){
				_ptr = _alloc.allocate(_capacity);
				size_t i = 0;
				for (iterator it = x.begin(); it != x.end(); it++){
					_alloc.construct(&_ptr[i], *it);
					i++;
				}
			};
			
			/* @Brief Destructor, destroys all the vector's elements and then deallocates vector's */
			/* ressources. */
			~vector(){
				this->clear();
				this->_alloc.deallocate(_ptr, _capacity);
				this->_size_alloc = 0;
				this->_capacity = 0;
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
			 /* ------------------------- OPERATOR -------------------------- */  
			 /* @Brief Returns a reference to the element at position n in the vector container. */
			 /* @Param Position of an element in the container. */
			 /* @Return The element at the specified position in the vector. */
			 reference &operator[] (const size_type &n){return (_ptr[n]);}

			 /* @Brief Returns a const reference to the element at position n in the vector container. */
			 /* @Param Position of an element in the container. */
			 /* @Return The element at the specified position in the vector. */
			 const_reference &operator[] (const size_type &n) const{return (_ptr[n]);}


			 /* ------------------------------------------------------------- */
			 /* ------------------------- ITERATORS ------------------------- */
			 iterator	begin(void){return (iterator(_ptr));}
			 const_iterator	begin(void)const {return (const_iterator(_ptr));}
			 iterator	end(void){return (iterator(_ptr + _size_alloc));}
			 const_iterator	end(void)const{return (const_iterator(_ptr + _size_alloc));}
			
			 rev_iterator	rbegin(void){return (rev_iterator(_ptr + _size_alloc - 1));}
			 rev_const_iterator	crbegin(void)const {return (rev_const_iterator(_ptr + _size_alloc - 1));}
			 rev_iterator	rend(void){return (rev_iterator(_ptr - 1));}
			 rev_const_iterator	crend(void)const {return (rev_const_iterator(_ptr - 1));}

			 /* ------------------------------------------------------------- */
			 /* -------------------------- CAPACITY ------------------------- */
			 /* ------------------------------------------------------------- */

			 /* @Brief Returns the number of elements in the vector. */
			 /* @Return size allocation */
			 size_type	size() const { return (_size_alloc); };

			 /* @Brief Returns whether the vector is empty (i.e. whether its size is 0). */
			 /* @Return  Bool*/
			 bool      	empty() const{ return (_size_alloc < 1 ? true : false);}

			 /* @Brief Returns the size of the storage space currently allocated for the vector, */ 
			 /* @Return The size of the currently allocated storage capacity in the vector*/ 
			 size_t         capacity()const{ return (this->_capacity);}

			 /* @brief Returns the maximum number of elements that the vector can hold. */
			 /* @Return The size max*/ 
			 size_t 	max_size()const{ return (allocator_type().max_size());}

			 /* ------------------------------------------------------------- */
            		 /* ---------------------- ELEMENTS ACCESS ---------------------- */ 
			 /* ------------------------------------------------------------- */
			 
			 /* @brief Access element */
			 /* @Param position of an element */
			 /* @return reference */
			 reference at(size_type n){
				 if (n > _capacity)
					 throw std::out_of_range("vector::at");
				 return (_ptr[n]);
			 };
			 /* @brief Access element */
			 /* @Param position of an element */
			 /* @return const_reference */
			 const_reference at(size_type n)const{
				 if (n > _capacity)
					 throw std::out_of_range("vector::at");
				 return (_ptr[n]);
			 };

			 /* @brief Access first element */
			 /* @Returns a reference to the first element in the vector. */
			 reference front(void){return (*_ptr);};

			 /* @brief Access first element */
			 /* @Returns a const_reference to the first element in the vector. */
			 const_reference front(void)const{return (*_ptr);};

			 /* @Brief Access last element */
			 /* @Returns a reference to the last element in the vector. */
			 reference back(void){return (_ptr[_size_alloc  - 1]);}

			 /* @Brief Access last element */
			 /* @Returns a const reference to the last element in the vector. */
			 const_reference back(void)const{return (_ptr[_size_alloc - 1]);}

			 /* ------------------------------------------------------------- */
            		 /* ------------------------- MODIFIERS ------------------------- */
			 /* ------------------------------------------------------------- */
			/* @Brief Add element at the end*/
			/* @Param  const value_type val*/
			/* @Return  Return*/
			 void push_back (const value_type &val){
				 if (this->_size_alloc == this->_capacity){
					 int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
					 this->reserve(next_capacity);
				 }
				_alloc.construct(&_ptr[_size_alloc++], val);
			 }

			 /* @Brief Removes all elements from the vector*/
			 /* @Param  Void*/
			 /* @Return  Void*/
			 void clear(void){
				 for (size_type i = 0; i < _size_alloc; i++){
					 pop_back();
				 }
				 this->_alloc.deallocate(_ptr, _size_alloc);
				 this->_ptr = _alloc.allocate(_capacity);
				 this->_size_alloc = 0;
			 }

			/* @Brief Add element at the front*/
			/* @Param  const value_type val*/
			/* @Return  Return*/
			 void pop_back(void){
				 if (_size_alloc)
                    			_alloc.destroy(&_ptr[_size_alloc-- - 1]);
			 }

			 void resize (size_type n, value_type val = value_type()){
				 if (n < _size_alloc){
					 for (size_type i = 1; i < n; i++)
						 pop_back();
				 }
				 else if (n >= _size_alloc){
					for (size_type i = _size_alloc; i < n; i++)
						push_back(val);
				 }
			 }

			 void swap (vector& x){
				 __swap(x._alloc, _alloc);
				 __swap(x._ptr, _ptr);
				 __swap(x._capacity, _capacity);
				 __swap(x._size_alloc, _size_alloc);
			 }

			 /* @Brief Request a change in capacity */
			 /* @Param Minimum capacity for the vector. */
			 /* @Return NONE */
			 void reserve(size_t n){
				 if (n > this->max_size())
					 throw ("error::vector::size_max");
				 else if (n > this->capacity()){
					 Allocator t_alloc;
					 T *tmp = t_alloc.allocate(n);
					 for (size_t i = 0; i < this->size(); i++){
						 t_alloc.construct(tmp + i, _ptr[i]);
						 this->_alloc.destroy(&_ptr[i]);
					 }
					 this->_alloc.deallocate(_ptr, _size_alloc);
					 this->_alloc = t_alloc;
					 this->_ptr = tmp;
					 this->_capacity = n;
				 }
			 }

			 template <class InputIterator>
  			 void assign (InputIterator first, InputIterator last,
			 	typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
				 size_t n = ft::lenght_it(first, last);
				 this->clear();
				 if (this->_capacity < n)
					 this->reserve(n);
				 else
				 	for (; n > 0; n--)
		 		 		this->push_back(*first++);
				 this->_size_alloc = n;
			 };

			 void assign (size_type n, const value_type& val){
				 this->clear();
				 if (n > this->_capacity){
					 this->reserve(n);
				 }
				 for (size_type i = 0; i < n; i++)
					 this->push_back(val);
				 this->_size_alloc = n;

			 };

			 iterator erase (iterator position){
				 return (erase(position, position + 1));
			 };

		 	 iterator erase (iterator first, iterator last){
				size_type	len = last - first;
				if (last == this->end()){
					for (; len > 0; len--)
						this->pop_back();
				}
				else{
					iterator 	tmp_first = first;
					pointer 	tmp = _alloc.allocate(this->_capacity);
					size_type	tmp_capacity(_capacity);
					size_type	tmp_size(_size_alloc);
					size_type	i(0);
					size_type	j(0);
					for (iterator it = this->begin(); it != this->end(); it++){
						if (it < first || it >= last){
							_alloc.construct(&tmp[i], _ptr[j]);
							i++;
						}
						j++;
					}
					tmp_size -= static_cast<size_type>(last - first);
					this->~vector();
					this->_capacity = tmp_capacity;
					this->_size_alloc = tmp_size;
					this->_ptr = tmp;
				}
				return (first);
			 };

			 /* @Brief The vector is extended by inserting new elements before the element at the specified position*/
			 /* @Param  Position in the vector where the new elements are inserted.*/
			 /* @Param1 Value to be copied (or moved) to the inserted elements.*/
			 /* @Return  None*/
			 iterator insert (iterator position, const value_type& val){
			 	vector tmp;
				difference_type n = position - begin();
				
				(_size_alloc + 1 > _capacity) ? tmp.reserve(_capacity * 2) : tmp.reserve(_size_alloc + 1);
				for (iterator it = begin(); it != end(); it++){
					if (it == position)
						tmp.push_back(val);
					tmp.push_back(*it);
				}
				swap(*this, tmp);
				return (&_ptr[n]);
			 }

			 /* @Brief The vector is extended by inserting new elements before the element at the specified position*/
			 /* @Param  Position in the vector where the new elements are inserted.*/
			 /* @Param1 Number of elements to insert. Each element is initialized to a copy of val. */
			 /* @Param1 Value to be copied (or moved) to the inserted elements.*/
			 /* @Return  None*/
    			 void insert (iterator position, size_type n, const value_type& val){
				vector tmp;

				(_size_alloc + n > _capacity) ? tmp.reserve(_capacity * 2) : tmp.reserve(_size_alloc + n);
				for (iterator it = begin(); it != end(); it++){
					if (it == position){
						for (size_type i = 0; i < n; i++){
							tmp.push_back(val);
						}
					}
					tmp.push_back(*it);
				}
				swap(*this, tmp);
			 }

			 /* @Brief The vector is extended by inserting new elements before the element at the specified position*/
			 /* @Param  Position in the vector where the new elements are inserted.*/
			 /* @Param1 Iterators specifying a range of elements. Copies of the elements in the range first */
			 /* @Param1 Iterators specifying a range of elements. Copies of the elements in the range last */
			 /* @Return  None*/
			 template <class InputIterator>
    			 void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
				vector tmp;
				size_type n = static_cast<size_type>(last - first);

				(_size_alloc + n > _capacity) ? tmp.reserve(_capacity * 2) : tmp.reserve(_size_alloc + n);
				for (iterator it = begin(); it != end(); it++){
					if (it == position){
						for (; first != last; first++){
							tmp.push_back(*first);
						}
					}
					tmp.push_back(*it);
				}
				swap(*this, tmp);
			 }

			 /* @Brief Returns a copy of the allocator object associated with the vector.*/
			 /* @Param  Void*/
			 /* @Return  allocator*/
			 allocator_type get_allocator() const{ return (_alloc);}


			 /* ------------------------------------------------------------- */
            		 /* --------------- NON-MEMBER FUNCTION OVERLOADS --------------- */
  			 friend bool operator== (const vector& lhs, const vector& rhs);
  			 friend bool operator!= (const vector& lhs, const vector& rhs);
  			 friend bool operator<  (const vector& lhs, const vector& rhs);
  			 friend bool operator<= (const vector& lhs, const vector& rhs);
  			 friend bool operator>  (const vector& lhs, const vector& rhs);
  			 friend bool operator>= (const vector& lhs, const vector& rhs);
  			 void swap (vector &x, vector &y){
				 x.swap(y);
			 }

		private:
			template <typename U>
			/* @Brief Swap two variable using reference*/
			/* @Param  a*/
			/* @Param  b*/
		   	void __swap(U& a, U&b)
		    	{
				U tmp = a;
				a = b;
				b = tmp;
		    	}
};

template < class T >
std::ostream& operator <<(std::ostream &s, ft::vector<T> &v) 
{
	if (!v.empty())
		return (s);
	std::cout << v.empty() << std::endl;
	s << "{";
	for (ft::iterator<T> it = v.begin(); it != v.end(); it++){
		s << *it << ", ";
	}
	s << v[v.size() - 1] << "}";
	return s;
}
}
#endif
