/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:18:56 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 17:20:22 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

template<typename T>
class	Array{
	private:	
		T	*_arr;
		size_t	_size;
		
	public:
		Array(void);
		Array(size_t n);
		Array(const Array &Array);
		~Array(void);
		size_t size(void)const;

		Array &operator = (const Array &arr);
		T &operator [](const size_t index)const;
		T &operator [](const size_t index);
		class IndexOutOfBoundsException: public std::exception{
			public:
				char const *what() const throw();
		};
};
/* ...........................implementation................................ */ 

template<typename T>
Array<T>::Array(void): _arr(new T[0]), _size(0){
	return ;
}

template<typename T>
Array<T>::Array(size_t n): _arr(new T[n]), _size(n){
	return ;
}

template<typename T>
Array<T>::~Array(void){
	/* std::cout << "Destructor called" << std::endl; */
	delete [] this->_arr;
	return ;
}

template<typename T>
Array<T>::Array(const Array &array): _arr(new T[array.size()]), _size(array.size()){
	std::cout << "Copy constructor called" << std::endl;
	for (size_t i = 0; i < _size; i++){
		this->_arr[i] = array._arr[i];
	}
	return;
}

template<typename T>
Array<T> &Array<T>::operator = (const Array &array){
	std::cout << "copie" << std::endl;
	if (&array != this)
	{
		delete [] this->_array;
		this->_size = array._size();
		for (size_t i = 0; i < _size; i++){
			this->_arr[i] = array._arr[i];
		}
	}
	return (*this);
}

template<typename T>
size_t Array<T>::size(void)const{
	return (this->_size);
}

template<typename T>
T &Array<T>::operator [] (const size_t index)const{
	if (index >= this->_size)
		throw Array<T>::IndexOutOfBoundsException();
	return (this->_arr[index]);
}

template<typename T>
T &Array<T>::operator [] (const size_t index){
	if (index >= this->_size)
		throw Array<T>::IndexOutOfBoundsException();
	return (this->_arr[index]);
}

template<typename T>
char const *Array<T>::IndexOutOfBoundsException::what() const throw(){
	return ("Index out of the limits!");
}
#endif
