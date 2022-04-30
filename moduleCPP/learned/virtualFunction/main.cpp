/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:47:13 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/28 21:31:33 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Printable{
	public:
		virtual std::string getClassName(void)const = 0;
};

class	Entity : public Printable{
	public:
		//virtual permet d'utilisé une fonction de differente class suivant la class *
		
		/* virtual std::string getName(void)const { */
		/* 	return ("Entity"); */
		/* } */

		//virtal pure function 
		virtual std::string getName(void)const{
			return ("Entity");
		};
		std::string getClassName(void)const override{
			return ("Entity");
		}
};


class Player : public Entity{
	private:
		std::string _name;
	public:
		Player(const std::string & name): _name(name){}
		std::string getClassName(void)const override{
			return ("Player");
		}
		std::string getName(void)const override{
			return ("Player");
		}
};

void print(Printable *obj){
	std::cout << obj->getClassName() << std::endl;
}


void	printName(Entity *e){
	//function prend class Entity *e avec getname en virtual il va regardé si ces la class entity ou la class Player
	std::cout << e->getName() << std::endl;
}

int main(void)
{
	//virtual fonction in class
	/* Entity *e = new Entity(); */

	//Pure viratul fonction;
	Entity *e = new Player("Pure");
	/* printName(e); */

	Player *p = new Player("todo");
	/* printName(p); */

	print(e);
	print(p);

	std::cin.get();
	return 0;
}
