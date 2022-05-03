/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:07:15 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 18:35:51 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.hpp"

/* @Brief constructor */
/* @Return  NONE */
Cast::Cast(void){
	/* std::cout << "Default constructor called" << std::endl; */
	return ;
}

/* @Brief constructor*/
/* @Param std::string input*/
/* @Return NONE*/
Cast::Cast(const std::string &input): _input(input){
	_type = this->getType();
	this->setValue();
	return ;
}

Cast::~Cast(void){
	/* std::cout << "Destructor called" << std::endl; */
	return ;
}

Cast::Cast(const Cast &conv){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = conv;
	return;
}

Cast &Cast::operator = (const Cast &cast){
	if (&cast != this)
	{
		_value = cast._value;
		_type = cast._type;
		_input = cast._input;
	}
	return (*this);
}

type	Cast::getType(void)const{
	return (this->_type);
}

double	Cast::getValue(void)const{
	return (this->_value);
}

std::string	Cast::getInput(void)const{
	return (this->_input);
}

/* *********************************************************************************************************** */
/* Part check type input 										       */ 
/* https://www.educative.io/edpresso/how-to-convert-a-string-to-an-int-in-cpp 				       */
/* https://www.cplusplus.com/reference/sstream/istringstream/                                                  */
/* https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/                                    */
/* https://www.cplusplus.com/reference/istream/istream/seekg/                                                  */
/* *********************************************************************************************************** */

/* @Brief Reset istringstream*/
/* @Param std::istringstream &iss*/
/* @Return BOOL*/
static	bool	ft_reset_iss(std::istringstream &iss){
	iss.clear();
	iss.seekg(0, iss.beg);
	return (true);
}

/* @Brief check Int Type*/
/* @Param std::istringstream &iss*/
/* @Return Bool*/
bool	Cast::checkInt(std::istringstream &iss){
	int num;

	ft_reset_iss(iss);
	iss >> num;
	if (iss.eof() && !iss.fail())
		return (true);
	return (false);
}

/* @Brief check Double Type*/
/* @Param std::istringstream &iss*/
/* @Return Bool*/
bool Cast::checkDouble(std::istringstream &iss){
	double d_num;

	ft_reset_iss(iss);
	iss >> d_num;
	if (iss.eof() && !iss.fail())
		return (true);
	return (false);
}

/* @Brief check Float Type*/
/* @Param std::istringstream &iss*/
/* @Return Bool*/
bool	Cast::checkFloat(std::istringstream & iss){
	s_float		f;

	ft_reset_iss(iss);
	iss >> f.num;
	iss >> f.dot;
	iss >> f.num_dec;
	iss >> f.f;
	if (f.f == "f" && f.dot == '.' && iss.eof() && !iss.fail())
		return (1);
	return (0);
}

/* @Brief check Specail Type*/
/* @Param std::istringstream &iss*/
/* @Return int8_t*/
int8_t	Cast::checkSpecial(type *ret){
	std::string arg[] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};

	for (int i = 0; i < 6; i++){
		if (this->_input == arg[i]){
			*ret = (i < 3 ? T_SPECIAL : T_SPECIAL_F);
			std::cout << "ret value "<< *ret << std::endl;
			return (*ret);
		}
	}
	return (0);
}

/* @Brief get the type of the input gen  by the constructor*/
/* @Return  type*/
type	Cast::getType(void){
	std::istringstream 	iss(_input);
	type			ret;

	if (checkSpecial(&ret))
		return (ret > 0 ? ret : T_IMPOSSIBLE);
	if (_input.length() == 1 && !std::isdigit(_input[0]))
		return (T_CHAR);
	else if (checkInt(iss))
		return (T_NUM);
	else if (checkFloat(iss) || checkDouble(iss))
		return (T_FLOAT);
	return (T_IMPOSSIBLE);
}

/* *********************************************************************************************************** */
/* Set value in private _value by type 							                       */
/* *********************************************************************************************************** */

/* @Brief Fonction set la _value suivant le type trouver*/
/* @Return  NONE*/
void	Cast::setValue(void){
	std::istringstream 	iss(_input);
	s_float			f;

	if (this->_type == T_CHAR){
		iss >> f.dot;
		this->_value = f.dot;
	}
	else if (this->_type == T_NUM){
		iss >> f.num;
		this->_value = f.num;
	}
	else if (this->_type == T_FLOAT){
		iss >> f.num;
		iss >> f.dot;
		iss >> f.num_dec;
		this->_value = f.num;
		f.double_dec = f.num_dec;
		while (f.double_dec > 1)
			f.double_dec /= 10;
		this->_value += f.double_dec;
	}
	else
		iss >> this->_value;
}

/* *********************************************************************************************************** */
/* Print 			 							                       */
/* *********************************************************************************************************** */


/* @Brief Print char*/
void	Cast::printChar(void)const{
	std::cout << "char: ";

	if (this->_type == T_IMPOSSIBLE || this->_type == T_SPECIAL || this->_type == T_SPECIAL_F)
		std::cout << "impossible";
	else if (std::isprint(static_cast<char>(this->_value)))
		std::cout << "\'" << static_cast<char>(this->_value) << "\'";
	else if (!std::isprint(static_cast<char>(this->_value)))
		std::cout << "Non Displayable";
	std::cout << std::endl;
}

/* @Brief Print int*/
void	Cast::printInt(void)const{
	std::cout << "int: ";

	if (this->_type == T_IMPOSSIBLE || this->_type == T_SPECIAL || this->_type == T_SPECIAL_F)
		std::cout << "impossible";
	else if (static_cast<int>(this->_value) == std::numeric_limits<int>::min() && this->_input != "-2147483648")
		std::cout << "\'" << "Overfload";
	else
		std::cout << this->_value;
	std::cout << std::endl;
}

/* @Brief Print float*/
void	Cast::printFloat(void)const{
	std::cout << "float: ";

	if (_type == T_SPECIAL)
		std::cout << _input << "f";
	else if (_type == T_SPECIAL_F)
		std::cout << _input;
	else if (_type == T_IMPOSSIBLE)
		std::cout << "impossible";
	else 
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_value) << "f";
	std::cout << std::endl;
}

/* @Brief Print double*/
void	Cast::printDouble(void)const{
	std::cout << "double: ";

	if (_type == T_SPECIAL)
		std::cout << _input;
	else if (_type == T_SPECIAL_F)
		std::cout << _input.substr(0, _input.size() - 1);
	else if (_type == T_IMPOSSIBLE)
		std::cout << "impossible";
	else 
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(_value);
	if (_type == T_IMPOSSIBLE && (_value ==  -1 * std::numeric_limits<double>::max() || _value == std::numeric_limits<double>::max()))	
		std::cout << " (lol Bigger nb?)";

	std::cout << std::endl;
}

/* @Brief Print les convertion */
/* @Return NONE*/
void	Cast::printConv(void)const{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

/* @Brief change operator << of the class*/
/* @Param std::ostream &o*/
/* @Param1 const Cast s*/
/* @Return  Return(ostream)*/
std::ostream &operator << (std::ostream &o, const Cast s){
	o << "info: " <<  s.getInput() << "\n\ttype: " << s.getType() << "\n\tvalue: " << s.getValue() << std::endl;
	return (o);
}
