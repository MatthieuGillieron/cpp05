/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:11:49 by mg                #+#    #+#             */
/*   Updated: 2025/12/09 10:35:19 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


// === CANONICAL ===

AForm::AForm() : _name("Default"), _gradeToSign(1), _gradeToExecute(1),  _isSigned(false)
{};

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
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

AForm::AForm(const AForm& val) : _name(val._name),  _gradeToSign(val._gradeToSign),
			_gradeToExecute(val._gradeToExecute), _isSigned(val._isSigned)
{};

AForm::~AForm()
{};

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}



// === GETTERS ===

const std::string& AForm::getName() const { return _name; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

bool AForm::getIsSigned() const { return _isSigned; }



// === METHODE ===

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->getGradeToSign())
	{
		_isSigned = true;
	}
	else
		throw AForm::GradeTooLowException();

}


void AForm::checkExecuteRequirements(Bureaucrat const & executor) const
{
	if (AForm::getIsSigned() == false)
	{
		throw FormNotSigned();
	}

	else if (executor.getGrade() > getGradeToExecute())
	{
		throw GradeTooLowException();
	}
}





// === EXCEPTIONS ===

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("Form not signed!");
}



// === OPERATOR ===

std::ostream& operator<<(std::ostream& os, const AForm& f)
	{
		os << "name: " <<  f.getName() << "\n"
		<< " - sign grade: " << f.getGradeToSign() << "\n"
		<< " - execute grade: " << f.getGradeToExecute() << "\n"
		<< " - is signed: " << f.getIsSigned() << "\n";
		return os;
	}

