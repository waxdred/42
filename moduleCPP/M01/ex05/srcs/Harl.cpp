#include "Harl.hpp"

Harl::Harl(void){
	return ;
}

Harl::~Harl(void){
	return ;
}

void	Harl::debug(void){
	std::cout << "[DEBEUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void){
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void){
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void){
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level){
	int	index;
	std::string opt[] = {"DEBEUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*arr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	index = -1;
	for (int i = 0; i < MAX_OPTION; i++)
		if (opt[i] == level)
			index = i;
	if (index == -1){
		std::cout << "[ " << level << " ] level not implemented!" << std::endl; 
		return ;
	}
	(this->*arr[index])();
}
