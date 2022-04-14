
#ifndef SED_HPP
# define SED_HPP
# include <iostream>
# include <limits>
# include <fstream>


class	Sed
{
	private:
		std::fstream &_file;
		std::string _name;
	public:
		Sed(std::fstream &file, std::string name);
		std::string getName(void) const;
		~Sed(void);
		void	sed_file(std::string s1, std::string s2);
		std::string ft_sed_line(std::string line, std::string s1, std::string s2);
};

#endif
