#include <iostream>


int  main(void)
{
	std::string A = "HI THIS IS BRAIN";
	std::string *stringPTR = &A;
	std::string &stringREF = A;

	std::cout << "Memory adress of string: " << &A << std::endl;
	std::cout << "Memory adress held stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory adress held stringREF: " << stringREF << std::endl << std::endl;
	std::cout << "Value pointed of string: " << A << std::endl;
	std::cout << "Value pointed of stringPTR: " << stringPTR << std::endl;
	std::cout << "Value pointed of stringREF: " << stringREF << std::endl;
	return (0);
}

