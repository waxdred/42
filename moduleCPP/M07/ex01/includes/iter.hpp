/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:52:30 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 13:10:17 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	printValue(const T &arr){
	std::cout << arr << std::endl;
}

template <typename T>
void decrement(T &arr){
	arr--;
}

template <typename T>
void increment(T &arr){
	arr++;
}

template<typename T, typename U>
void	iter(T array[],const size_t size, U fn){
	for (size_t i = 0; i < size; i++){
		fn(array[i]);		
	}
}

#endif


