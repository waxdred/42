/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rev_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:17:02 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/21 10:28:39 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REV_ITERATOR
#define MAP_REV_ITERATOR 

#include "pair.hpp"
#include <algorithm>
#include <iterator>
#include <stdexcept>
namespace ft{
	/**
    	* ------------------------------------------------------------- *
    	* ---------------------- FT::MAP_ITERATOR --------------------- *
    	*
    	* - Coplien form:
    	* [x](constructor):        Construct map_iterator
    	* [x](destructor):         Map_iterator destructor
    	* [x]operator=:            Assign content
    	*
    	* - Operators
    	* [x]operators:            Operators for map_iterator
    	* [x]non-member operators: Operators for map_iterator
    	* ------------------------------------------------------------- *
	*  https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html#begin-and-end-
    	*/

	template <class Key, class T, class Compare, typename Node>
	class map_rev_iterator{
		/* ------------------------------------------------------------- */
        	/* -------------------------- ALIASES -------------------------- */
		public:
			typedef Key					key_type;
			typedef Compare					key_compare;
			typedef T 					mapped_type;

			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef long int 				difference_type;
			typedef size_t					size_type;

			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef Node					*nodePtr;
			typedef value_type				*reference;
			typedef T* 					pointer;

		private:
			nodePtr		_root;
			nodePtr		_node;
			nodePtr		_last;
			key_compare	_comp;

		public:
			map_rev_iterator(void): _root(0), _node(0), _last(0){
			}
			map_rev_iterator(nodePtr node,
                        	const key_compare& comp = key_compare()) :
                		_comp(comp) {
				_root = __findRoot(node);
				_node = node;
				_last = this->__findMin(_root);
			}

			map_rev_iterator(const map_rev_iterator<Key, T, Compare, Node> &copy){
				_root = copy.getRoot();
				_node = copy.getNode();
				_comp = copy.getComp();
				_last = copy.getLast();
			}
			~map_rev_iterator(){};
			map_rev_iterator &operator=(const map_rev_iterator &assign){
				if (this != &assign)
				{
					_node = assign.getNode();
					_comp = assign.getComp();
					_last = assign.getLast();
					_root = assign.getRoot();
				}
				return (*this);
			}

		/* ------------------------------------------------------------- */
        	/* -------------------------- GETTER  -------------------------- */
			nodePtr getNode()const {return (_node);}
			nodePtr getRoot()const {return (_root);}
			nodePtr getLast()const {return (_last);}
			key_compare getComp()const {return (_comp);}

		/* ------------------------------------------------------------- */
        	/* -------------------------- Operators------------------------- */
			reference operator*() const{return(_node->content);}
			reference operator->() const{return(&_node->content);}

			map_rev_iterator &operator++(){
				Node *t;
				if (_node == _last){
					_node = _last->left;
					return (*this);
				}
				if (_node->left){
					_node = _node->left;
					if (_node->right)
					         _node = __findMax(_node->left);
				}
				else{
					t = _node->parent;
					while(t && _node == t->left){
						_node = t;
						t = t->parent;
					}
					_node = t;
				}
				return (*this);
			};

			map_rev_iterator &operator++(int){
				Node *t;
				if (_node == _last){
					_node = _last->left;
					return (*this);
				}
				if (_node->left){
					_node = _node->left;
					if (_node->right)
					         _node = __findMax(_node->left);
				}
				else{
					t = _node->parent;
					while(t && _node == t->left){
						_node = t;
						t = t->parent;
					}
					_node = t;
				}
				return (*this);
			}

			map_rev_iterator &operator--(){
				Node *t;
				if (_node == _last){
					_node = _last->right;
					return (*this);
				}
				if (_node->right){
					_node = _node->right;
					if (_node->left)
					         _node = __findMin(_node->left);
				}
				else{
					t = _node->parent;
					while(t && _node == t->right){
						_node = t;
						t = t->parent;
					}
					_node = t;
				}
				return (*this);
			}

			map_rev_iterator &operator--(int){
				Node *t;
				if (_node == _last){
					_node = _last->right;
					return (*this);
				}
				if (_node->right){
					_node = _node->right;
					if (_node->left)
					         _node = __findMin(_node->left);
				}
				else{
					t = _node->parent;
					while(t && _node == t->right){
						_node = t;
						t = t->parent;
					}
					_node = t;
				}
				return (*this);
			}

			/* ------------------------------------------------------------- */
			/* --------------------- BOOL OPERATOR ------------------------- */
			bool operator==(const map_rev_iterator &it)const { return (it._node == _node);}
			bool operator!=(const map_rev_iterator &it)const { return (it._node != _node);}
			bool operator <(const map_rev_iterator &it)const { return (it._node > _node);}
			bool operator >(const map_rev_iterator &it)const { return (it._node < _node);}
			bool operator <=(const map_rev_iterator &it)const { return (it._node >= _node);}
			bool operator >=(const map_rev_iterator &it)const { return (it._node <= _node);}

		private:
			Node* __findMin(Node* t)
    			{
    			    	if(t == NULL)
    					return NULL;
    			    	else if(t->left == NULL)
    			        	return t;
    			    	else
    			        	return __findMin(t->left);
    			}
    			
    			Node* __findMax(Node* t)
    			{
    				if(t == NULL)
    			    		return NULL;
    				else if(t->right == NULL)
    			    	    	return t;
    				else
    			    	    	return __findMax(t->right);
    			}

    			Node* __findRoot(Node* t)
    			{
    				if(t == NULL)
    			    		return NULL;
    				else if(t->parent == NULL)
    			    	    	return t;
    				else
    			    	    	return __findRoot(t->parent);
    			}


	};// map_rev_iterator
        
}//namespace
#endif /* ifndef MAP_ITERATOR */

