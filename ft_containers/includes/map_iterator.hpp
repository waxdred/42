/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:53:10 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/25 00:44:14 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR
#define MAP_ITERATOR 

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
			nodePtr		_root;
			nodePtr		_node;
			nodePtr		_last;
			key_compare	_comp;

		public:
			map_iterator(void): _root(0), _node(0), _last(0){
			}
			map_iterator(nodePtr node,
                        	const key_compare& comp = key_compare()) :
                		_comp(comp) {
				_root = __findRoot(node);
				_node = node;
				_last = this->__findMax(_root);
			}
			map_iterator(const map_iterator<Key, T, Compare, Node> &copy){
				_root = copy.getRoot();
				_node = copy.getNode();
				_comp = copy.getComp();
				_last = copy.getLast();
			}
			~map_iterator(){};
			map_iterator &operator=(const map_iterator &assign){
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

			map_iterator &operator++(){
				_node = __next(_node); 
				return (*this);
			};


			map_iterator &operator++(int){
				map_iterator &ret(*this);

				_node = __next(_node);
				return (ret);
			}

			map_iterator &operator--(){
				_node = __prev(_node);
				return (*this);
			}

			map_iterator &operator--(int){
				map_iterator &ret(*this);

				_node = __prev(_node);
				return (*ret);
			}

			/* ------------------------------------------------------------- */
			/* --------------------- BOOL OPERATOR ------------------------- */
			bool operator==(const map_iterator &it)const { return (it._node == _node);}
			bool operator!=(const map_iterator &it)const { return (it._node != _node);}
			bool operator <(const map_iterator &it)const { return (it._node > _node);}
			bool operator >(const map_iterator &it)const { return (it._node < _node);}
			bool operator <=(const map_iterator &it)const { return (it._node >= _node);}
			bool operator >=(const map_iterator &it)const { return (it._node <= _node);}

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

			Node* __next(Node *t)
			{
				if(t == NULL)
					return NULL;
				else if(t->right != NULL)
					return __findMin(t->right);
				else
				{
					Node *p = t->parent;
					while(p != NULL && t == p->right)
					{
						t = p;
						p = p->parent;
					}
					return p;
				}
			}

			Node* __prev(Node *t)
			{
				if(t == NULL)
					return NULL;
				else if(t->left != NULL)
					return __findMax(t->right);
				else
				{
					Node *p = t->parent;
					while(p != NULL && t == p->left)
					{
						t = p;
						p = p->parent;
					}
					return p;
				}
			}

	};// map_iterator
        
}//namespace
#endif /* ifndef MAP_ITERATOR */
