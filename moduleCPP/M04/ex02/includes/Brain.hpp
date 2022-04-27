#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define MAX_IDEAS 100

class	Brain{
	private:	
		std::string _ideas[MAX_IDEAS];
	public:
		Brain(void);
		Brain(const Brain &Brain);
		~Brain(void);

		Brain &operator = (const Brain &brain);
};
#endif
