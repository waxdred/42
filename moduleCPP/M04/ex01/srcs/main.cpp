#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define MAX_SIZE 10
#define LEN 15
int main(void)
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        
        delete meta;
        delete i;
        delete j;
    }
    std::cout << std::endl << "!!!!!! Bad way !!!!!!!" << std::endl;
    {
        WrongAnimal* meta = new WrongAnimal();
        WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        meta->makeSound();
        
        delete meta;
        delete i;
    }
    std::cout << std::endl << "!!!!!! allocate array !!!!!!!" << std::endl;
    {
        Animal* animals[LEN];
        int i = 0;
        while (i < LEN / 2)
            animals[i++] = new Cat();
        animals[i - 1]->makeSound();
        while (i < LEN)
            animals[i++] = new Dog();
        animals[i - 1]->makeSound();
        /* if (animals[i - 1]->getBrain()) */
        /*     animals[i - 1]->getBrain()->setIdeaI(2, "yolo"); */
        Animal* animals2[LEN];
        Animal tmp;
        i = 0;
        while (i < LEN)
        {
            tmp = *(animals[i]);
            animals2[i] = &tmp;
            std::cout << animals2[i]->getType() << std::endl;
            i++;
        }
        /* if (animals2[i - 1]->getBrain()) */
        /*     std::cout << "the good idea is yolo : " */
        /*         << animals2[i - 1]->getBrain()->getIdeaI(2) << std::endl; */
        i = 0;
        while (i < LEN)
            delete animals[i++];
    }
	return 0;
}
