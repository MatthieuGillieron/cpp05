/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:11:49 by mg                #+#    #+#             */
/*   Updated: 2025/12/04 10:00:53 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


// === CANONICAL ===

Form::Form() : _isSigned(false), _name("Default"), _gradeToSign(1), _gradeToExecute(1)
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

Form::Form(const Form& val) : _gradeToSign(val._gradeToSign), _gradeToExecute(val._gradeToExecute) {};

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


