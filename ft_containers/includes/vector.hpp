/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:46 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 00:12:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include "vector_iterator.hpp"
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
    * [ ]rbegin:               Return reverse iterator to reverse beginning
    * [ ]rend:                 Return reverse iterator to reverse end
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
    * [ ]relational operators: Relational operators for vector
    * [x]swap:                 Exchange contents of two vectors
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
                    		typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) :
                    			_alloc(alloc), _size_alloc(0){
				while (first != last){
					push_back(*first);
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
				this->clear();
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
			 /* ------------------------- OPERATOR -------------------------- */  
			 /* Returns a reference to the element at position n in the vector container. */
			 /* A similar member function, vector::at, has the same behavior as this operator function, */ 
			 /* except that vector::at is bound-checked and signals */ 
		  	 /* if the requested position is out of range by throwing an out_of_range exception. */
			 /* Portable programs should never call this function with an argument n that is out of range, */ 
		         /* since this causes undefined behavior. */
			 /* @Param Position of an element in the container. */
			 /* Notice that the first element has a position of 0 (not 1). */
			 /* Member type size_type is an unsigned integral type. */
			 /* @Return The element at the specified position in the vector. */
			 /* If the vector object is const-qualified, the function returns a const_reference. */		 
			 /* Otherwise, it returns a reference. */
			 /* Member types reference and const_reference are the reference types */ 
			 /* to the elements of the container (see vector member types). */
			 reference &operator[] (const size_type &n){return (_ptr[n]);}
			 const_reference &operator[] (const size_type &n) const{return (_ptr[n]);}


			 /* ------------------------------------------------------------- */
			 /* ------------------------- ITERATORS ------------------------- */
			 iterator	begin(void){return (iterator(_ptr));}
			 const_iterator	begin(void)const {return (const_iterator(_ptr));}
			 iterator	end(void){return (iterator(_ptr + _size_alloc));}
			 const_iterator	end(void)const {return (const_iterator(_ptr + _size_alloc));}
			
			 /* ------------------------------------------------------------- */
			 /* -------------------------- CAPACITY ------------------------- */
			 /* ------------------------------------------------------------- */

			 /* @Brief Returns the number of elements in the vector. */
			 /* This is the number of actual objects held in the vector */
			 /* which is not necessarily equal to its storage capacity. */
			 size_type	size() const { return (_size_alloc); };

			 /* @Brief Returns whether the vector is empty (i.e. whether its size is 0). */
			 /* This function does not modify the container in any way. */
			 /* To clear the content of a vector, see vector::clear. */
			 /* @Return  Bool*/
			 bool      	empty() const{ return (_size_alloc < 1 ? false : true);}

			 /* @Brief Returns the size of the storage space currently allocated for the vector, */ 
		  	 /* expressed in terms of elements. */
			 /* This capacity is not necessarily equal to the vector size. */ 
			 /* It can be equal or greater, */ 
			 /* with the extra space allowing to accommodate for growth without the need to reallocate on each insertion. */
			 /* Notice that this capacity does not suppose a limit on the size of the vector. */
			 /* When this capacity is exhausted and more is needed, */ 
			 /* it is automatically expanded by the container (reallocating it storage space). */ 
			 /* The theoretical limit on the size of a vector is given by member max_size. */
			 /* The capacity of a vector can be explicitly altered by calling member vector::reserve. */
			 /* @Return The size of the currently allocated storage capacity in the vector, */ 
			 /* measured in terms of the number elements it can hold. */
			 size_t         capacity()const{ return (this->_capacity);}

			 /* Returns the maximum number of elements that the vector can hold. */
			 /* This is the maximum potential size the container can reach due to */ 
			 /* known system or library implementation limitations, */ 
			 /* but the container is by no means guaranteed to be able to reach that size: */ 
		         /* it can still fail to allocate storage at any point before that size is reached. */
			 size_t 	max_size()const{ return (allocator_type().max_size());}

			 /* ------------------------------------------------------------- */
            		 /* ---------------------- ELEMENTS ACCESS ---------------------- */ 
			 /* ------------------------------------------------------------- */
			 
			 /* Access element */
			 /* Returns a reference to the element at position n in the vector. */
			 /* The function automatically checks whether n is within the bounds of valid elements in the vector, */ 
			 /* throwing an out_of_range exception */ 
			 /* if it is not (i.e., if n is greater than, or equal to, its size). */    
			 /* This is in contrast with member operator[], that does not check against bounds. */
			 /* @Param position of an element */
			 reference at(size_type n){return (_ptr[n]);};
			 const_reference at(size_type n)const {return (_ptr[n]);};

			 /* Access first element */
			 /* Returns a reference to the first element in the vector. */
			 /* Unlike member vector::begin, which returns an iterator to this same element, */
			 /* this function returns a direct reference. */
			 /* Calling this function on an empty container causes undefined behavior. */
			 reference front(void){return (*_ptr);};
			 const_reference front(void)const{return (*_ptr);};

			 /* Access last element */
			 /* Returns a reference to the last element in the vector. */
			 /* Unlike member vector::end, which returns an iterator just past this element, */ 
			 /* this function returns a direct reference. */
			 /* Calling this function on an empty container causes undefined behavior. */
			 reference back(void){return (_ptr[_size_alloc  - 1]);}
			 const_reference back(void)const{return (_ptr[_size_alloc - 1]);}

			 /* ------------------------------------------------------------- */
            		 /* ------------------------- MODIFIERS ------------------------- */
			 /* ------------------------------------------------------------- */

			 void push_back (const value_type val){
				 if (this->_size_alloc == this->_capacity){
					 int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
					 this->reserve(next_capacity);
				 }
				_alloc.construct(&_ptr[_size_alloc++], val);
			 }

			 void clear(void){
				 for (size_type i = 0; i < _size_alloc; i++){
					 pop_back();
				 }
				 this->_alloc.deallocate(_ptr, _size_alloc);
				 this->_ptr = 0;
				 this->_size_alloc = 0;
			 }

			 void pop_back(void){
				this->_size_alloc--;
				if (!this->_size_alloc)
					_alloc.destroy(&_ptr[_size_alloc - 1]);
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
				 swap(x._alloc, _alloc);
				 swap(x._ptr, _ptr);
				 swap(x._capacity, _capacity);
				 swap(x._size_alloc, _size_alloc);
			 }

			 /* Request a change in capacity */
			 /* Requests that the vector capacity be at least enough to contain n elements. */
			 /* If n is greater than the current vector capacity, */ 
			 /* the function causes the container to reallocate its storage increasing its capacity to n (or greater). */
			 /* In all other cases, the function call does not cause a reallocation and the vector capacity is not affected. */
			 /* This function has no effect on the vector size and cannot alter its elements. */
			 /* @Param Minimum capacity for the vector. */
			 /* Note that the resulting vector capacity may be equal or greater than n. */
			 /* Member type size_type is an unsigned integral type. */
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
				 return (this->erase(position, position + 1));
			 };

		 	 iterator erase (iterator first, iterator last){
				if (first == this->end() || first == last)
					return (first);
				size_type index = first - this->begin();
				if (last < this->end()){
					moveleft(first, last);
					_size_alloc -= static_cast<size_type>(last - first);
				}
				else{
					size_type new_size = static_cast<size_type>(last - first);
					while (_size_alloc < new_size)
						this->pop_back();
				}
				return (&_ptr[index]);
			 };
			 /* iterator insert (iterator position, const value_type& val){ */
			 /* size_type index = position - this->begin(); */
				 /* this->insert(position, 1, val); */
				 /* return (iterator(&(_ptr[index]))); */

			 /* } */
    			 /* void insert (iterator position, size_type n, const value_type& val){ */
				 /* size_type index = position - this->begin(); */
				 /* if (_size_alloc + n > _capacity) */
					 /* this->reserve(_capacity + n); */
			 /* } */
			 /* template <class InputIterator> */
    			 /* void insert (iterator position, InputIterator first, InputIterator last, */
				/* typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){ */

			 /* } */

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
		   	void swap(U& a, U&b)
		    	{
				U tmp = a;
				a = b;
				b = tmp;
		    	}
			void moveleft(iterator first, iterator last){
				for(; first != this->end(); first++){
					_alloc.destroy(&(*first));
				}
				if (last < this->end()){
					_alloc.construct(&(*first), *last);
				}

			}

};

template < class T >
std::ostream& operator <<(std::ostream &s, ft::vector<T> &v) 
{
	if (!v.empty())
		return (s);
	std::cout << v.empty() << std::endl;
	s << "{";
	for (ft::vector_iterator<T> it = v.begin(); it != v.end(); it++){
		s << *it << ", ";
	}
	s << v[v.size() - 1] << "}";
	return s;
}
}
#endif
