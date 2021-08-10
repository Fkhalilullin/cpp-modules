#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	this->_name = "noName";
	this->_grade = 150;
}


Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) {
	this->_name = name;
	if (grade > 150) {
		throw GradeTooLowException();
		exit(0);
	}
	if (grade < 1) {
		throw GradeTooHighException();
		exit(0);
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs) {
	this->_grade = rhs.getGrade();
	this->_name = rhs.getName();
	
	return *this;
}

void Bureaucrat::gradeToHight() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::gradeToLow() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}


std::string Bureaucrat::getName() const {
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{ 
	return ("Grade too low");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

void Bureaucrat::signForm(Form &form) {
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " cannot sign " << form.getName() << " because "
			<< e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout << this->getName() << " executes " << form.getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (out);
}
