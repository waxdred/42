#include "../includes/Sed.hpp"
#include <string>

Sed::Sed(std::fstream &ifs, std::string s1, std::string s2):
	_ifs(ifs), _s1(s1), _s2(s2){
	std::cout << "File found !!!" << std::endl;
	return;
}

Sed::~Sed(void){
	_ifs.close();
	return;
}

void	Sed::sed_file(void)
{
	std::ofstream fileout("../test");
	std::string line;

	while(std::getline(_ifs, line))
	{
		if (line.find(_s1) != std::string::npos)
		{
			std::cout << line << std::endl;
			line = "test";
		}
		line = "test";
		_ifs << line << std::endl;
	}
	fileout.close();

}
