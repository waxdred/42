#include "Sed.hpp"
#include <limits>

Sed::Sed(std::fstream &file, std::string name): _file(file), _name(name){
	_file.open(_name, std::fstream::in | std::fstream::out);
	if (file.is_open())
		std::cout << "File found !!!" << std::endl;
	else
	{
		std::cout << "File not found !!!" << std::endl;
		exit(-1);
	}
	return;
}

std::string	Sed::getName(void) const{
	return (this->_name);
}

Sed::~Sed(void){
	_file.close();
	return;
}

std::string	Sed::ft_sed_line(std::string line, std::string s1, std::string s2)
{
	std::string	sed;
	std::size_t	pos;

	while ((pos = line.find(s1)) != std::string::npos)
	{
		sed.append(line, 0, pos);
		sed.append(s2);
		line.erase(0, pos + s1.length());
	}
	sed.append(line);
	return (sed);
}

void	Sed::sed_file(std::string s1, std::string s2)
{
	std::string	line;
	std::size_t	found;

	while (_file)
	{
		std::getline(_file, line);
		found = line.find(s1);
		if (found != std::string::npos)
		{
			_file << ft_sed_line(line, s1, s2) << std::endl;
		}
		else
			_file << line << std::endl;
	}
}
