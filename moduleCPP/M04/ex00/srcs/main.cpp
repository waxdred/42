#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal 	*a = new Animal();
	const Animal 	*b = new Cat();
	const Animal 	*c = new Dog();
	WrongAnimal *d = new WrongAnimal();
	WrongAnimal *e = new WrongCat();

	std::cout << a->getType() << " " << std::endl;
	std::cout << b->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	a->makeSound();
	b->makeSound();
	c->makeSound();

	std::cout << "\nWrong Animal" << std::endl;
	std::cout << d->getType() << " WrongAnimal" << std::endl;
	std::cout << e->getType() << " WrongCat" << std::endl;
	d->makeSound();
	e->makeSound();

	delete a;
	delete b;
	delete c;
	delete d;
	return 0;
}
