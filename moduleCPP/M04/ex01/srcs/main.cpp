#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "../includes/Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal *a = new Cat();

	a->makeSound();
	delete
	return 0;
}
