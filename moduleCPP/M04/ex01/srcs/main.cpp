#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define MAX_SIZE 10
int main(void)
{
	Animal *animal[MAX_SIZE];

	std::cout << "Allocation des class dog and cat" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++){
		if (i % 2)
			animal[i] = new Cat;
		else
			animal[i] = new Dog;
	}
	std::cout << "\nFree des class dog and cat" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++){
		delete animal[i];
	}
	return 0;
}
