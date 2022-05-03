/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:39:35 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/03 08:48:06 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iterator>

template<typename T>
MutantStack<T>::MutantStack() : MutantStack<T>::stack(){
	/* std::cout << "Default constructor called" << std::endl; */
	return ;
}

template<typename T>
MutantStack<T>::~MutantStack(void){
	/* std::cout << "Destructor called" << std::endl; */
	return ;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &name): MutantStack<T>::stack(name){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = name;
	return;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator = (const MutantStack &mutant){
	if (&mutant != this){
		MutantStack<T>::stack::operator=(mutant);
	}
	return (*this);
}
