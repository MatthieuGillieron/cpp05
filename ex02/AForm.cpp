/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:11:49 by mg                #+#    #+#             */
/*   Updated: 2025/12/06 19:40:10 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


// === CANONICAL ===

Form::Form() : _name("Default"), _gradeToSign(1), _gradeToExecute(1),  _isSigned(false)
{};

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150)
		throw GradeTooLowException();

	if (gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150)
		throw GradeTooLowException();
	
};

Form::Form(const Form& val) : _name(val._name),  _gradeToSign(val._gradeToSign),
			_gradeToExecute(val._gradeToExecute), _isSigned(val._isSigned)
{};

Form::~Form()
{};

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}



// === GETTERS ===

const std::string& Form::getName() const { return _name; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

bool Form::getIsSigned() const { return _isSigned; }



// === METHODE ===

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->getGradeToSign())
	{
		_isSigned = true;
	}
	else
		throw Form::GradeTooLowException();

}



// === EXCEPTIONS ===

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}



// === OPERATOR ===

std::ostream& operator<<(std::ostream& os, const Form& f)
	{
		os << "name: " <<  f.getName() << "\n"
		<< " - sign grade: " << f.getGradeToSign() << "\n"
		<< " - execute grade: " << f.getGradeToExecute() << "\n"
		<< " - is signed: " << f.getIsSigned() << "\n";
		return os;
	}

