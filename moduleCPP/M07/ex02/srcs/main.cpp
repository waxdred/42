/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:18:20 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 17:22:08 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 70

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
	    const int value = rand();
	    numbers[i] = value;
	    mirror[i] = value;
	}
	//SCOPE
	{
	    Array<int> tmp = numbers;
	    const Array<int> test(numbers);
	    tmp[0] = 10;
	    /* // test[0] = 10; should give error!! Const can't be changed! */
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
	    if (mirror[i] != numbers[i])
	    {
	        std::cerr << "didn't save the same value!!" << std::endl;
	        return 1;
	    }
	}
	try
	{
	    numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
	    std::cerr << e.what() << '\n';
	}
	try
	{
	    numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
	    std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
	    numbers[i] = rand();
	    if (i % 2 == 0)
	        std::cout << "[" << i << "]: " << numbers[i] << std::endl;
	}
    delete [] mirror;//
    return 0;
}
