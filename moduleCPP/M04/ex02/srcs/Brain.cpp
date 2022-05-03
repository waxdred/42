# include "Brain.hpp"

Brain::Brain(void){
	std::cout << "[Brain] Default constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++)
		_ideas[i] = "Have no idea!";
	return ;
}

Brain::~Brain(void){
	std::cout << "[Brain] Destructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain &brain){
	std::cout << "[Brain] Copy constructor called" << std::endl;
	*this = brain;
	return;
}

Brain &Brain::operator = (const Brain &brain){
	std::cout << "[Brain] Copy operator called" << std::endl;
	if (&brain != this)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
			_ideas[i] = brain._ideas[i];
	}
	return (*this);
}

