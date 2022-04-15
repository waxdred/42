#include "Sed.hpp"
#include <fstream>
#include <limits>

Sed::Sed(std::fstream &file) : _file(file){
}

bool	Sed::setSed(std::string name){
	setName(name);
	_file.open(_name, std::fstream::in);
	if (_file.is_open())
		std::cout << "File found !!!" << std::endl;
	else
	{
		std::cout << "File not found !!!" << std::endl;
		return (false);
	}
	return (true);
}

void Sed::setName(std::string name){
	this->_name = name;
}

std::string	Sed::getName(void) const{
	return (this->_name);
}

Sed::~Sed(void){
	_file.close();
	std::cout << "close fd and kill constructor" << std::endl;
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

void	Sed::sedFile(std::string s1, std::string s2)
{
	std::string	line;
	std::string	tmp;
	std::size_t	found;

	while (_file)
	{
		std::getline(_file, line);
		found = line.find(s1);
		if (found != std::string::npos)
			tmp.append(ft_sed_line(line, s1, s2));
		else
			tmp.append(line);
		tmp += "\n";
	}
	_file.close();
	_file.open(_name, std::fstream::out | std::fstream::trunc);
	_file << tmp;
}
