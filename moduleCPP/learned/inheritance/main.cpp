/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:36:04 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/28 20:45:38 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Entity{
	public:
		float x, y;
		void Move(float xa, float ya){
			x += xa;
			y += ya;
		}
};

class Player : public Entity{
	public:
		const char *_name;
		void printName(void){
			std::cout << this->_name << std::endl;
		}
	
};

int main(void)
{
	std::cout << "sizeof Entity " << sizeof(Entity) << std::endl;
	std::cout << "sizeof Player " << sizeof(Player) << std::endl;
	Player player;

	player.Move(5, 5);
	player.x = 2;
	std::cin.get();
	return 0;
}
