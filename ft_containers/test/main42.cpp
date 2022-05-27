/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main42.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:27:03 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/27 16:33:58 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"
#include <chrono>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

template<typename T>
class OMutantStack : public std::stack<T>
{
public:
	OMutantStack() {}
	OMutantStack(const OMutantStack<T>& src) { *this = src; }
	OMutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~OMutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

std::string ft_container(std::string n){
	std::stringstream my;

	const int seed = std::atoi(n.c_str());
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	/* ft::map<int, int> map_int; */

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
			/* my << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl; */
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	/* for (int i = 0; i < COUNT; ++i) */
	/* { */
	/* 	map_int.insert(ft::make_pair(rand(), rand())); */
	/* } */

	/* int sum = 0; */
	/* for (int i = 0; i < 10000; i++) */
	/* { */
	/* 	int access = rand(); */
	/* 	sum += map_int[access]; */
	/* } */
	/* std::cout << "should be constant with the same seed: " << sum << std::endl; */

	/* { */
	/* 	ft::map<int, int> copy = map_int; */
	/* } */
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
		my << *it;
	}
	std::cout << std::endl;

	std::string my_vector = my.str();
	return (my_vector);
}

std::string std_container(std::string n){
	std::stringstream origine;
	
	const int seed = atoi(n.c_str());
	srand(seed);

	std::vector<std::string> vector_str;
	std::vector<int> vector_int;
	std::stack<int> stack_int;
	std::vector<Buffer> vector_buffer;
	std::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	/* ft::map<int, int> map_int; */

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	std::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
			origine << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	/* for (int i = 0; i < COUNT; ++i) */
	/* { */
	/* 	map_int.insert(ft::make_pair(rand(), rand())); */
	/* } */

	/* int sum = 0; */
	/* for (int i = 0; i < 10000; i++) */
	/* { */
	/* 	int access = rand(); */
	/* 	sum += map_int[access]; */
	/* } */
	/* std::cout << "should be constant with the same seed: " << sum << std::endl; */

	/* { */
	/* 	ft::map<int, int> copy = map_int; */
	/* } */
	OMutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (OMutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
		origine << *it;
	}
	std::cout << std::endl;
	std::string origine_vector = origine.str();
	return (origine_vector);
}

int main(void)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	std::string my_vector = ft_container("42");
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	std::chrono::seconds duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
	std::cerr << duration.count() << " sec" << std::endl;

	std::chrono::time_point<std::chrono::high_resolution_clock> start1 = std::chrono::high_resolution_clock::now();
	std::string origine_vector =  std_container("42");
	std::chrono::time_point<std::chrono::high_resolution_clock> stop1= std::chrono::high_resolution_clock::now();
	std::chrono::seconds duration1 = std::chrono::duration_cast<std::chrono::seconds>(stop1 - start1);
	std::cerr << duration1.count() << " sec"<< std::endl;

	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
