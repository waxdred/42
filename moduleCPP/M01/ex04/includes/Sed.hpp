
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
		Sed(void);
		std::string getName(void) const;
		~Sed(void);
		Sed(std::fstream &file);
		bool	setSed(std::string name);
		void	sedFile(std::string s1, std::string s2);
		void    setName(std::string name);
		std::string ft_sed_line(std::string line, std::string s1, std::string s2);
};

#endif
