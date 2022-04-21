#include "Sed.hpp"

Sed::Sed(void){
}

bool	Sed::setSed(std::string name){
	if (name.empty())
	{
		std::cout << "Error Name file is empty" << std::endl;
		return (false);
	}
	setName(name);
	_fdin.open(_name, std::fstream::in);
	_fdout.open(_nameReplace, std::fstream::out | std::fstream::trunc);
	if (_fdin.is_open())
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
	this->_nameReplace = name.append(".replace");
}

std::string	Sed::getName(void) const{
	return (this->_name);
}

Sed::~Sed(void){
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

	while (_fdin)
	{
		std::getline(_fdin, line);
		if (!s1.empty() && line.find(s1) != std::string::npos)
			_fdout << ft_sed_line(line, s1, s2);
		else
			_fdout << line;
		_fdout << "\n";
	}
	_fdout.close();
}

void	Sed::readFile(void){
	
	std::string	line;
	_fdout.open(_nameReplace, std::fstream::in);

	while (_fdout)
	{
		std::getline(_fdout, line);
		std::cout << line << std::endl;
	}
	_fdout.close();
}
