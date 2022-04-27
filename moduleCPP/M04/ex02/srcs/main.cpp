#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <cstdio>

int main(void)
{
	Animal *cat = new Cat();
	Animal *dog = new Dog();

	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;
	return 0;
}
