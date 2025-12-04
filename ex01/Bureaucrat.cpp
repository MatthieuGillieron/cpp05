/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:43:11 by mg                #+#    #+#             */
/*   Updated: 2025/12/04 11:40:11 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


// === CANONICAL FORM / OPERATOR ===

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat() : _name("default") {};

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
};

Bureaucrat::Bureaucrat(const Bureaucrat& val) : _name(val._name), _grade(val._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = (other._grade);
	}
	return (*this);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}



// === GETTER ===

const std::string& Bureaucrat::getName() const { return _name;} 
int Bureaucrat::getGrade() const { return _grade; }



// === INCREMENTATION / DECREMENTATION ===

void Bureaucrat::incrementGrade() 
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() 
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}



// === METHODE 	===

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}

	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " 
		<< form.getName() << " because " << e.what() << std::endl;
	}
	
}




// === LOG FOR ERROR ===

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}