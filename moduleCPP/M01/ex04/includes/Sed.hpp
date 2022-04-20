
#ifndef SED_HPP
# define SED_HPP
# include <fstream>
# include <iostream>

class	Sed
{
	private:
		std::fstream &_fdin;
		std::fstream &_fdout;
		std::string _name;
		std::string _nameReplace;
	public:
		std::string getName(void) const;
		~Sed(void);
		Sed(std::fstream &fdin, std::fstream &fdout);
		bool	setSed(std::string name);
		void	sedFile(std::string s1, std::string s2);
		void    setName(std::string name);
		void	readFile(void)const;
		std::string ft_sed_line(std::string line, std::string s1, std::string s2);
};

#endif
