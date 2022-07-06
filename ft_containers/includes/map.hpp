/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:52:47 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/06 15:09:06 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "pair.hpp"
#include "iterators_traits.hpp"
#include <i386/endian.h>
# include <iostream>
# include <memory>
#include <utility>

/**
    * ------------------------ TODO ------------------------------- *
    * ------------------------ FT::MAP ---------------------------- *
    *
    * - Coplien form:
    * [ ](constructor):        Construct vector
    * [ ](destructor):         Destruct vector
    * [ ]operator=:            Assign vector
    *
    * - Iterators:
    * [ ]begin:                Return iterator to beginning
    * [ ]end:                  Return iterator to end
    * [ ]rbegin:               Return reverse iterator to reverse beginning
    * [ ]rend:                 Return reverse iterator to reverse end
    *
    * - Capacity:
    * [ ]empty:                Test whether container is empty 
    * [ ]size:                 Return container size
    * [ ]max_size:             Return maximum size 
    *
    * - Element access:
    * [ ]operator[]:           Access element 
    *
    * - Modifiers:
    * [ ]insert:	       insert elements
    * [ ]erase:		       erase elements 
    * [ ]swap:		       swap content
    * [ ]clear:		       clear content 
    * 
    * - Observers:
    * [ ] key_comp	       Return key comparison object
    * [ ] value_comp	       Return value comparison object
    *
    * - Operations:
    * [ ]find:		       Get iterator to element
    * [ ]count:		       Count elements with a specific key
    * [ ]lower_bound:   	       Return iterator to lower bound
    * [ ]upper_bound:  	       Return iterator to upper bound
    * [ ]equal_range: 	       Get range of equal elements
    *
    * - Allocator:
    * [ ] get_allocator:       Get allocator
    * ------------------------------------------------------------- *
    */

namespace ft
{

template < class Key,                                     			// map::key_type
			class T,                                       		// map::mapped_type
			class Compare = std::less<Key>,                     	// map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >    	// map::allocator_type
			> class map{
	private:
		/* ------------------------------------------------------------- */
            	/* ------------------------- NodeStruct ------------------------ */
		struct  Node{
			ft::pair<const Key, T>		content;
			Node				*parent;
			Node				*left;
			Node				*right;
		};
	public:
		/* ------------------------------------------------------------- */
            	/* ------------------------- ALIASES --------------------------- */
		typedef Key							key_type;
		typedef T							mapped_type;
		typedef Alloc							allocator_type;
		typedef Compare							key_compare;

		typedef pair<const key_type,mapped_type>			value_type;
		typedef long int						difference_type;
		typedef size_t							size_type;

		typedef T&							reference;
		typedef const T&						const_reference;
		typedef T*							pointer;
		typedef const T*						const_pointer;

		typedef mapIterator<value_type>				iterator;
		typedef mapIterator<const const value_type>			const_iterator;
		typedef bidir_rev_it<iterator>				reverse_iterator;
		typedef bidir_rev_it<const_iterator>				const_reverse_iterator;
		class value_compare
		{   
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const{
				return comp(x.first, y.first);
			}
		};

		private:
			Node			*_root;
			Node 			*_last;
			size_type		_size;
			allocator_type		_allocPair;
			key_compare		_comp;
			std::allocator<Node>	_allocNode;

		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()):
			_size(0), _allocPair(alloc), _comp(comp){
			_last = createNode(std::pair<const key_type, mapped_type>());
			_root = _last;
			_last->right = _last;
			_last->left = _last;
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		{}
		map (const map& x): _size(0),_allocPair(x._allocPair), _comp(x._comp), _allocNode(x._allocNode){
			_last  = this->createNode(std::pair<const key_type, mapped_type>());
			_root = _last;
			_last->right = _last;
			_last->left = _last;
			for (const_iterator it = x.begin(); it != x.end(); ++it)
				insert(*it);
		}
		~map() {
			this->clear();
			this->deallocateNode(_last);
		}
		map& operator= (const map& x) {
			map tmp(x);

			this->swap(tmp);
			return *this;
		}
		/* iterator begin() {} */
		/* const_iterator begin() const {} */
		/* iterator end() {} */
		/* const_iterator end() const {} */
		/* reverse_iterator rbegin() {} */
		/* const_reverse_iterator rbegin() const {} */
		/* reverse_iterator rend() {} */
		/* const_reverse_iterator rend() const {} */
		bool empty() const {}
		size_type size() const {}
		size_type max_size() const {}
		mapped_type& operator[] (const key_type& k) {}
		/* pair<iterator,bool> insert (const value_type& val) {} */
		/* iterator insert (iterator position, const value_type& val) {} */
		template <class InputIterator>
		/* void insert (InputIterator first, InputIterator last) {} */
		void erase (iterator position) {
		}
		size_type erase (const key_type& k) {}
		void erase (iterator first, iterator last) {}
		void swap (map& x) {
			swap(_root, x._root);
			swap(_last, x._last);
			swap(_size, x._size);
			swap(_comp, x._comp);
			swap(_allocPair, x._allocPair);
			swap(_allocNode, x._allocNode);
		}
		void clear() {}
		key_compare key_comp() const {}
		value_compare value_comp() const {}
		/* iterator find (const key_type& k) {} */
		/* const_iterator find (const key_type& k) const {} */
		size_type count (const key_type& k) const {}
		/* iterator lower_bound (const key_type& k) {} */
		/* const_iterator lower_bound (const key_type& k) const {} */
		/* iterator upper_bound (const key_type& k) {} */
		/* const_iterator upper_bound (const key_type& k) const {} */
		/* pair<const_iterator,const_iterator> equal_range (const key_type& k) const {} */
		/* pair<iterator,iterator>             equal_range (const key_type& k) {} */
		allocator_type get_allocator() const {}
		
	private:
		/* ------------------------------------------------------------- */
            	/* ------------------------- Private Function ------------------ */
		/* @Brief Create new node and assign pair.*/
		/* set pointer left right at NULL */
		/* @Param  value_type &pair*/
		/* @Return  Return newNode*/
		Node *createNode(const value_type &pair){
			Node *newNode = _allocNode.allocate(1);

			_allocNode.construct(&newNode->content, pair);
			newNode->parent = 0;
			newNode->right = 0;
			newNode->left = 0;
			return newNode;
		}

		/* @Brief deallocateNode*/
		/* @Param  Node *node */
		void deallocateNode(Node *node){
			_allocPair.destroy(&node->content);
			_allocPair.deallocate(node, 1);
		}
		/* @Brief Swap two variable using reference*/
		/* @Param  a*/
		/* @Param  b*/
		template<typename U>
		void swap(U &a, U &b){
			U tmp = a;
			a = b;
			b = tmp;
		}

};



} // namespace ft
