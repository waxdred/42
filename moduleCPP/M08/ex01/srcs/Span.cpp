/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:33:22 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 15:11:15 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::Span(void): _n(0){
	/* std::cout << "Default constructor called" << std::endl; */
	return ;
}

Span::Span(size_t n): _n(n), _v(){
	/* std::cout << "Default constructor called" << std::endl; */
	return ;
}

Span::~Span(void){
	/* std::cout << "Destructor called" << std::endl; */
	return ;
}

Span::Span(const Span &span){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = span;
	return;
}

void	Span::addNumber(int n){
	if (_v.size() >= this->_n)
		throw Span::FullBufferException();
	this->_v.push_back(n);
}

void 	Span::addNumber(const std::initializer_list<int> &list){
	if (_v.size() + list.size() >= this->_n)
		throw Span::FullBufferException();
	for (auto it = list.begin(); it != list.end(); it++){
		this->_v.push_back(*it);
	}
}

void	Span::addNumber(const std::vector<int> &vect){
	if (_v.size() + (long)vect.size() >= this->_n)
		throw Span::FullBufferException();
	for (auto it = vect.begin(); it != vect.end(); it++){
		this->_v.push_back(*it);
	}

}


long	Span::shortestSpan(void){
	if (this->_v.size() < 2)
		throw Span::CantSearchException();
	std::vector<int> copy = _v;
	long			ret;

	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator prev = copy.begin(); 
	std::vector<int>::iterator next = ++copy.begin(); 

	ret = (long)*next - (long)*prev;
	while (next != copy.end()){
		if ((long)*next - (long)*prev < ret)
			ret = (long)*next - (long)*prev;
		prev = next;
		next++;
	}
	return (ret);	
}

long	Span::longestSpan(void){
	if (this->_v.size() < 2)
		throw Span::CantSearchException();
	std::vector<int> copy = _v;
	std::sort(copy.begin(), copy.end());
	return ((long)copy.back() - (long)copy.front());	
}



Span &Span::operator = (const Span &span){
	if (&span != this)
		_n = span._n;
	return (*this);
}
