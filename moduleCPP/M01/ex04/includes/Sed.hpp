
#ifndef SED_HPP
# define SED_HPP
#include <algorithm>
# include <iostream>
# include <fstream>
#include <string_view>

class	Sed
{
	private:
		std::fstream &_ifs;
		std::string _s1;
		std::string _s2;
	public:
		Sed(std::fstream &ifs, std::string s1, std::string s2);
		~Sed(void);
		void	sed_file(void);
		

};

#endif
