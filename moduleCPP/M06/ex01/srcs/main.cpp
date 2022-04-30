/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:12:31 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 19:43:39 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

/* @Brief fonction cast data en uintptr_t*/
/* @Param  Param*/
/* @Return  Return(<uintptr_t>ptr)*/
uintptr_t serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

/* @Brief fonction cast uintptr_t en Data*/
/* @Param  uintptr_t ptr*/
/* @Return  Return(<Data>ptr)*/
Data* deserialize(uintptr_t ptr){
	return (reinterpret_cast<Data*>(ptr));

}

void	print_data(const Data &data){
	std::cout << "name: " << data.name << std::endl;
	std::cout << "âges: " << data.ages << std::endl;
	std::cout << "gender: " << (data.gender ? "Male" : "Female") << std::endl;
 	std::cout << std::endl;
 	std::cout << std::endl;
}

int	main(void)
{
	Data data = {"todo", 40, true};
	uintptr_t ptr;
	Data *convert;

	std::cout << "************************" << std::endl;
	std::cout << "*    Print user set    *" << std::endl;
	std::cout << "************************" << std::endl;
	print_data(data);
	
	ptr = serialize(&data);
	convert = deserialize(ptr);
	std::cout << "**********************" << std::endl;
	std::cout << "*    Print adress    *" << std::endl;
	std::cout << "**********************" << std::endl << std::endl;
	std::cout << "adress of data: " << &data << std::endl;
	std::cout << "adress of serialize ptr: " << &ptr << std::endl;
	std::cout << "value  of serialize ptr: " << ptr << std::endl;
	std::cout << "adress of deserialize convert: " << convert << std::endl << std::endl;
	
	std::cout << "***************************" << std::endl;
	std::cout << "*    Print user change    *" << std::endl;
	std::cout << "***************************" << std::endl;
	convert->name = "foo";
	convert->ages = 18;
	convert->gender = false;
	print_data(data);
	ptr = serialize(&data);
	convert = deserialize(ptr);
	std::cout << "***********************************" << std::endl;
	std::cout << "*    Print adress after change    *" << std::endl;
	std::cout << "***********************************" << std::endl << std::endl;
	std::cout << "adress of data: " << &data << std::endl;
	std::cout << "adress of serialize ptr: " << &ptr << std::endl;
	std::cout << "value  of serialize ptr: " << ptr << std::endl;
	std::cout << "adress of deserialize convert: " << convert << std::endl << std::endl;
	return 0;
}

