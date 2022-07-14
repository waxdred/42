/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:53:10 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/14 02:45:36 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR
#define MAP_ITERATOR 

#include "pair.hpp"
#include <algorithm>
#include <iterator>
namespace ft{
	/**
    	* ------------------------------------------------------------- *
    	* ---------------------- FT::MAP_ITERATOR --------------------- *
    	*
    	* - Coplien form:
    	* [x](constructor):        Construct map_iterator
    	* [x](destructor):         Map_iterator destructor
    	* [x]operator=:            Assign content
    	* [ ]
    	* - Operators
    	* [ ]operators:            Operators for map_iterator
    	* [ ]non-member operators: Operators for map_iterator
    	* ------------------------------------------------------------- *
	*  https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html#begin-and-end-
    	*/

	template <class Key, class T, class Compare, typename Node, bool B>
	class map_iterator{
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
			nodePtr		_node;
			nodePtr		_last;
			key_compare	_comp;

		public:
			map_iterator(nodePtr node,
                        	const key_compare& comp = key_compare()) :
                		_comp(comp) {
				_node = this->findMin(node);
				_last = this->findMax(node);
			}
			map_iterator(const map_iterator<Key, T, Compare, Node, false> &copy){
				_node = copy.getNode();
				_comp = copy.getComp();
			}
			~map_iterator(){};
			mapped_type &operator=(const map_iterator &assign){
				if (this != &assign)
				{
					_node = assign.getNode();
					_comp = assign.getComp();
				}
				return (*this);
			}

		/* ------------------------------------------------------------- */
        	/* -------------------------- GETTER  -------------------------- */
			nodePtr getNode()const {return (_node);}
			key_compare getComp()const {return (_comp);}

		/* ------------------------------------------------------------- */
        	/* -------------------------- Operators------------------------- */
			reference operator*() const{return(_node->content);}
			reference operator->() const{return(&_node->content);}

			map_iterator &operator++(){
				Node *t;
				if (_node->right){
					while (_node->left) {
						_node = _node->left;
					}
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
			};

			map_iterator &operator++(int){
			}

			map_iterator &operator--(){
			}

			map_iterator &operator--(int){
			}

			bool operator==(const map_iterator &it)const { return (it._node == _node);}
			bool operator!=(const map_iterator &it)const { return (it._node != _node);}

		private:
			Node* findMin(Node* t)
    			{
    			    	if(t == NULL)
    					return NULL;
    			    	else if(t->left == NULL)
    			        	return t;
    			    	else
    			        	return findMin(t->left);
    			}
    			
    			Node* findMax(Node* t)
    			{
    				if(t == NULL)
    			    		return NULL;
    				else if(t->right == NULL)
    			    	    	return t;
    				else
    			    	    	return findMax(t->right);
    			}


	};// map_iterator
        
}//namespace
#endif /* ifndef MAP_ITERATOR */
