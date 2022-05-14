#include "Form.hpp"

Form::Form() :
	_name("F000 Y00"),
	_gradeToSign(150),
	_gradeToExecute(150),
	_isSigned(false)
{
	//std::cout << "[FORM] Default constructor called" << std::endl;
	return;
}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExecute) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_isSigned(false)
{
	//std::cout << "[FORM] Default constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	return;
}

Form::~Form() {
	//std::cout << "[FORM] Destructor called" << std::endl;
	return;
}

Form::Form(const Form &form) :
	_name(form.getName()),
	_gradeToSign(form.getGradeToSign()),
	_gradeToExecute(form.getGradeToExecute()),
	_isSigned(form.getIsSigned())
{
	//std::cout << "[FORM] Copy constructor called" << std::endl;
	*this = form;
	return;
}

Form & Form::operator= (const Form &form) {
	//std::cout << "[FORM] Copy assignment operator called" << std::endl;
	if (this != &form) {
		_isSigned = form.getIsSigned();
	}
	return (*this);
}

const std::string Form::getName() const {
	return (this->_name);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

bool Form::getIsSigned() const {
	return (this->_isSigned);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}


char const* Form::GradeTooHighException::what() const throw() {
	return ("Form: Grade to high dude!");
}

char const* Form::GradeTooLowException::what() const throw() {
	return ("Form: So low grade man!");
}

std::ostream & operator<< (std::ostream & o, Form const & form) {
	o << "Form: " <<  form.getName()
	<< " | Grade to Sign: " << form.getGradeToSign()
	<< " | Grade to Sign: " << form.getGradeToExecute()
	<< " | Is signed ? " << (form.getIsSigned() ? "Yeeep!" : "Nooup!");
	
	return (o);
}