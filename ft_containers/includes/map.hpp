/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:52:47 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/17 08:31:11 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "pair.hpp"
#include "iterators_traits.hpp"
#include "map_iterator.hpp"
#include "tools.hpp"
#include "vector_iterator.hpp"
#include <cstddef>
# include <iostream>
#include <iterator>
#include <algorithm>
# include <memory>
#include <ostream>

/**
    * ------------------------ TODO ------------------------------- *
    * ------------------------ FT::MAP ---------------------------- *
    * visualization AVLtree
    * https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
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
    * [x]empty:                Test whether container is empty 
    * [x]size:                 Return container size
    * [x]max_size:             Return maximum size 
    *
    * - Element access:
    * [x]operator[]:           Access element 
    *
    * - Modifiers:
    * [x]insert:	       insert elements
    * [x]erase:		       erase elements 
    * [x]swap:		       swap content
    * [x]clear:		       clear content 
    * 
    * - Observers:
    * [x] key_comp	       Return key comparison object
    * [ ] value_comp	       Return value comparison object
    *
    * - Operations:
    * [x]find:		       Get iterator to element
    * [x]count:		       Count elements with a specific key
    * [ ]lower_bound:          Return iterator to lower bound
    * [ ]upper_bound:  	       Return iterator to upper bound
    * [ ]equal_range: 	       Get range of equal elements
    *
    * - Allocator:
    * [x] get_allocator:       Get allocator
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
			Node                            *parent;
			Node				*left;
			Node				*right;
			long long int                   level;
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

		typedef typename ft::map_iterator<Key, T, Compare, Node> iterator;
		typedef typename ft::map_iterator<Key, T, Compare, Node> const_iterator;
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
		Node			*_last;
		size_type		_size;
		allocator_type		_allocPair;
		key_compare		_comp;
		std::allocator<Node>	_allocNode;
	public:

		/* @def empty container constructor (default constructor) */
                /* Constructs an empty container, with no elements. */
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()):
			_size(0), _allocPair(alloc), _comp(comp){
			_root = NULL;
			_last = NULL;
		}
		
		/* @def Constructs a container with as many elements as the range [first,last), */
		/* with each element constructed from its corresponding element in that range. */
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
		        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) :
				_size(0), _allocPair(alloc), _comp(comp){
			_root = NULL;
			_last = NULL;
               	 	for (; first != last; ++first)
                    		insert(first.getNode()->content);
		}

		/* @def Constructs a container with a copy of each of the elements in x. */
		map (const map& x): _size(0),_allocPair(x._allocPair), _comp(x._comp), _allocNode(x._allocNode){
			for (const_iterator it = x.begin(); it != x.end(); ++it)
				insert(*it);
		}
		
		/* @def This destroys all container elements, and */ 
		/* deallocates all the storage capacity allocated by the map container using its allocator. */
		~map() {
			iterator begin = this->begin();
			iterator end = this->end();

			while (begin != end){
				Node *t = begin.getNode();
				++begin;
				_allocNode.deallocate(t, 1);
			}
		}

		/* @Brief Assigns new contents to the container, replacing its current content.*/
		/* @Param  x  A map object of the same typedef */
		/* (i.e., with the same template parameters, key, T, Compare and Alloc).*/
		/* @Return  *This*/
		map& operator= (const map& x) {
			map tmp(x);

			this->swap(tmp);
			return *this;
		}

		/* ------------------------------------------------------------- */
            	/* ------------------------- Iterators ------------------------- */
		/* @Brief Return iterator to beginning*/
		/* @Param  None*/
		/* @Return  An iterator to the first element in the container.*/
		iterator begin() { return iterator(_root, _comp);}

		/* @Brief Return iterator to beginning const*/
		/* @Param  None*/
		/* @Return  An iterator to the first element in the container.*/
		const_iterator begin()const { return const_iterator(_root, _comp);}

		/* @Brief Return iterator to end*/ 
		/* @Param  None*/
		/* @Return  An iterator to the past-the-end element in the container.*/
		iterator end() {return iterator(_last->right, _comp);}

		/* @Brief Return iterator to end const*/ 
		/* @Param  None*/
		/* @Return  An iterator to the past-the-end element in the container.*/
		const_iterator end()const {return const_iterator(_last->right, _comp);}

		/* reverse_iterator rbegin() {} */
		/* const_reverse_iterator rbegin() const {} */
		/* reverse_iterator rend() {} */
		/* const_reverse_iterator rend() const {} */

		/* ------------------------------------------------------------- */
            	/* ------------------------- CAPACITY  ------------------------- */
		/* @Brief Test whether container is empty 
		 * Returns whether the map container is empty (i.e. whether its size is 0).
		 * This function does not modify the container in any way. 
		 * To clear the content of a map container, see map::clear.*/
		/* @Param  None*/
		/* @Return  true if the container size is 0, false otherwise.*/
		bool empty() const {return this->_size == 0;}

		/* @Brief Returns the number of elements in the map container.*/
		/* @Param  None*/
		/* @Return  The number of elements in the container.
		 * Member type size_type is an unsigned integral type.*/
		size_type size() const {return(this->_size);}

		/* @Brief Return maximum size */ 
		/* @Param  none*/
		/* @Return  The maximum number of elements a map container can hold as content*/
		size_type max_size() const {return (allocator_type().max_size());}

		/* @Brief If k matches the key of an element in the container*/ 
		/* @Param  const key_type &k*/
		/* @Return  A reference to the mapped value of the element with a key value equivalent to k*/
		mapped_type& operator[] (const key_type& k) {
			Node *t = SearchKey(_root, k);
			if (t)
				return (t->content.second);
			value_type val = ft::make_pair<key_type, mapped_type>(k, mapped_type());
			insert(val);
			Node *ret = SearchKey(_root, k);
			return (ret->content.second);
		}
		

		/* @Brief Extends the container by inserting new elements*/
		/* @Param  const value_type &val*/
		/* @Return  Pair<iterator, bool>*/
		pair<iterator,bool> insert (const value_type& val) {
			Node *t = SearchKey(_root,  val.first);
			if (t){
				return (ft::make_pair<iterator, bool>(iterator(t, _comp), false));
			}
			_root = avl_insert(this->_root, val, NULL);
			_size++;
			return (ft::make_pair<iterator, bool>(iterator(_root, _comp), true));
		}

		/* @Brief Extends the container by inserting new elements*/
		/* @Param  const value_type &val*/
		/* @Return  iterator*/
		iterator insert (iterator position, const value_type& val){
			position = NULL;
			iterator it(_root = avl_insert(_root, val, NULL));
			_size++;
			return (it);
		}

		/* @Brief Extends the container by inserting new elements*/
		/* @Param  const value_type &val*/
		/* @Return  None*/
		template <class InputIterator>
 		void insert (InputIterator first, InputIterator last,
		     typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
			while(first != last){
				insert(first.getNode()->content);
				_size++;
				++first;
			}

		}
		/* @Brief Removes from the map container either a single element or a range of elements*/
		/* @Param  iterator*/
		/* @Return  None*/
		void erase (iterator position) {
			Node *t = position.getNode();
			_root = remove(_root, t->content);
			--_size;
		}

		/* @Brief Removes from the map container either a single element or a range of elements*/
		/* @Param  key_type &k*/
		/* @Return  size_t / bool*/
		size_type erase (const key_type& k) {
                         Node *todel = SearchKey(_root, k);
			 if (!todel)
				 return (0);
			_root = remove(_root, ft::make_pair<key_type, mapped_type>(k, mapped_type()));
			--_size;
			return (1);

		}

		/* @Brief Removes from the map container either a single element or a range of elements*/
		/* @Param  iterator first*/
		/* @Param1  iterator end*/
		/* @Return  None*/
		void erase (iterator first, iterator last) {
			while (first != last){
				iterator tmp(first);
				++first;
				erase(tmp);
			}

		}

		/* @Brief Exchanges the content of the container*/
		/* @Param  map*/
		/* @Return  None*/
		void swap (map& x) {
			swap(_root, x._root);
			swap(_size, x._size);
			swap(_comp, x._comp);
			swap(_allocPair, x._allocPair);
			swap(_allocNode, x._allocNode);
		}

		/* @Brief Removes all elements from the map container*/
		/* @Param  Void*/
		/* @Return  None*/
		void clear(void) {
			this->erase(this->begin(), this->end());
		}

		key_compare key_comp() const {}
		/* @Brief Returns a copy of the comparison object used by the container to compare keys.*/
		/* @Param  void*/
		/* @Return  the comparison object*/
		value_compare value_comp() const { return (this->_comp);}

		/* @Brief Search the key in the tree*/
		/* @Param  const key_type &k*/
		/* @Return  iterator*/
		iterator find (const key_type& k) {
			return (iterator(SearchKey(_root, k)));
		}

		/* @Brief Search the key in the tree*/
		/* @Param  const key_type &k*/
		/* @Return  const_iterator*/
		const_iterator find (const key_type& k)const {
			return (iterator(SearchKey(_root, k)));
		}

		/* @Brief  Searches key in the tree and returns the element if it finds key.*/
		/* @Param  const key_type &k*/
		/* @Return  bool*/
		size_type count (const key_type& k) const {
			Node *t = SearchKey(_root, k);
			return (t ? true : false);
		}
		/* iterator lower_bound (const key_type& k) {} */
		/* const_iterator lower_bound (const key_type& k) const {} */
		/* iterator upper_bound (const key_type& k) {} */
		/* const_iterator upper_bound (const key_type& k) const {} */
		/* pair<const_iterator,const_iterator> equal_range (const key_type& k) const {} */
		/* pair<iterator,iterator>             equal_range (const key_type& k) {} */

		/* @Brief get copy of allocator type*/
		/* @Param  void*/
		/* @Return  _allocPair*/
		allocator_type get_allocator(void) const {return(this->_allocPair);}
		
		Node *getNode(void){
			return _root;
		}

	private:
		/* ------------------------------------------------------------- */
            	/* ------------------------- Private Function ------------------ */

		/* @Brief Create new node and assign pair.*/
		/* set pointer left right at NULL */
		/* @Param  value_type &pair*/
		/* @Return  Return newNode*/
		Node *createNode(const value_type &pair){
			Node *newNode = _allocNode.allocate(1);

			_allocPair.construct(&newNode->content, pair);
			newNode->right = NULL;
			newNode->left = NULL;
			newNode->level = 0;
			return newNode;
		}

		/* @Brief deallocateNode*/
		/* @Param  Node *node */
		void deallocateNode(Node *node){
			_allocPair.destroy(&node->content);
			_allocPair.deallocate(&node->content, 1);
		}

		/* @Brief check the level of the node*/
		/* @Param  Node *t*/
		/* @Return  new level*/
		long long int height(Node* t){
        		return (t == NULL ? -1 : t->level);
		}
		
		/* @Brief get delta height of 2 nodes*/
		/* @Param  Node *t*/
		/* @Param1  Node *n*/
		/* @Return  size_t t->level - n->level*/
		size_t deltaHeightSize(Node *t, Node *n){
			if (!t && n)	
				return(n->level);
			if (!n && t)	
				return(t->level);
			return (t->level - n->level);
		}

		/* @Brief rotation of the node right*/
		/*      	  Q                                 P     */     
 		/*               / \          RIGHT ROTATION       / \    */    
 		/*              P   C    ------------------->>>   A   Q   */   
 		/*             / \                                   / \  */  
 		/*            A   B                                 B   C */ 
		/* @Param  Node* &t*/
		Node *SRRotate(Node* &t){
			Node *u = t->left;

			u->parent = t->parent;
			t->left = u->right;
			u->right = t;
			u->right->parent = u;

			t->level = std::max(height(t->left), height(t->right)) + 1;
			u->level = std::max(height(u->left), u->level) + 1;
			return (u);
		}

		/* @Brief rotation of the node left*/
		/*      	  Q                                 P     */     
 		/*               / \          LEFT ROTATION        / \    */    
 		/*              P   C    <<<-------------------   A   Q   */   
 		/*             / \                                   / \  */  
 		/*            A   B                                 B   C */ 
		/* @Param  Node* &t*/
		/* @Return  Node**/
		Node *SLRotate(Node* &t){
			Node *u = t->right;

			u->parent = t->parent;
			t->right = u->left;
			u->left = t;
			u->left->parent = u;
			t->level = std::max(height(t->left), height(t->right)) + 1;
			u->level = std::max(height(u->left), u->level) + 1;
			return (u);
		}

		/* @Brief Make double rotation left*/
		/* @Param  Node *t */
		/* @Return  Node*/
		Node* DLRotate(Node* &t){
    		    	t->right = SRRotate(t->right);
    		    	return (SLRotate(t));
    		}

		/* @Brief Make double rotation right*/
		/* @Param  Node *t */
		/* @Return  Node*/
    		Node* DRRotate(Node* &t){
    		   	t->left = SLRotate(t->left);
    		    	return (SRRotate(t));
    		}

		/* @Brief Search the max key in the tree*/
		/* @Param  Node *t*/
		/* @Return  NodeFound / NULL*/
		Node* findMax(Node* t){
			if (!t)
				return (NULL);
			else if (!t->right)
				return (t);
			else
			        return findMin(t->right);
		}

		/* @Brief Search the min key in the tree*/
		/* @Param  Node *t*/
		/* @Return  NodeFound / NULL*/
		Node* findMin(Node* t){
			if (!t)
				return (NULL);
			else if (!t->right)
				return (t);
			else
			        return findMax(t->right);
		}

		/* @Brief insert in avl tree*/
		/* @Param  Node *t*/
		/* @Param1  const key_type &t*/
		/* @Param2  Node parent*/
		/* @Return  Node*/
		Node *avl_insert(Node *t, const value_type &pair, Node *parent){
			if (!t){
				t = createNode(pair);
				if (!_last || _last->content.first < pair.first)
					_last = t;
				t->parent = parent;
			}
			else if (pair < t->content){
				t->left = avl_insert(t->left, pair, t);
				if (height(t->left) - height(t->right) == 2){
					if (pair < t->left->content)
						t = SRRotate(t);
					else
						t = DRRotate(t);
				}
			}
			else if (pair > t->content){
				t->right = avl_insert(t->right, pair, t);
				if (height(t->right) - height(t->left) == 2){
					if (pair > t->right->content)
						t = SLRotate(t);
					else
						t = DLRotate(t);
				}
			}
			t->level = std::max(height(t->left), height(t->right)) + 1;
                        return t;
		}
		
		/* @Brief Search the key_type in the tree*/
		/* @Param  Node *t*/
		/* @Param1  const key_type &t*/
		/* @Return  Node / NULL*/
		Node *SearchKey(Node *t, const key_type &k) const{
			while (t){
				if (t->content.first == k)
					return (t);
				if (t->content.first < k)
					t = t->right;
				else if (t->content.first > k)
					t = t->left;
			}
			return (NULL);
		}

		/* @Brief Remove Node in the tree*/
		/* @Param  Node *t*/
		/* @Param1  const key_type &t*/
		/* @Return  Node*/
		Node *remove(Node *t, value_type const &pair){
			Node *tmp = t;

			if (!t)
				return (NULL);
			else if(pair.first < t->content.first)
            			t->left = remove(t->left, pair);
			else if(pair.first > t->content.first)
            			t->right = remove(t->right, pair);

			else if (t->left && t->right){
				tmp = findMin(t->right);
				_allocPair.deallocate(&t->content, 1);
				_allocPair.construct(&t->content, tmp->content);
				t->parent = tmp->parent;
				t->right = remove(t->right, pair);
			}else{
				tmp = t;
				if (!t->left)
					t = t->right;
				else if (!t->right)
					t = t->left;
				deallocateNode(tmp);
			}
			if (!t)
				return (t);
			t->level = std::max(height(t->left), height(t->right)) + 1;
			if(height(t->left) - height(t->right) == 2){
				if(height(t->left->left) - height(t->left->right) == 1)
					return SLRotate(t);
				else
					return DLRotate(t);
			}
			else if(height(t->right) - height(t->left) == 2){
				if(height(t->right->right) - height(t->right->left) == 1)
                                        return SRRotate(t);
				else
                                        return DRRotate(t);
			}
			return (t);
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
