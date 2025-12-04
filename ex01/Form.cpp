/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:11:49 by mg                #+#    #+#             */
/*   Updated: 2025/12/04 09:48:05 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


// === CANONICAL ===

Form::Form() : _isSigned(false), _name("Default"), _gradeToSign(1), _gradeToExecute(1) {};

Form::Form(const std::string& name, int gradeToSign, int gradeToexecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToexecute)
{
	// verif les erreurs
};

Form::Form(const Form& val) : _gradeToSign(val._gradeToSign), _gradeToExecute(val._gradeToExecute) {};

Form::~Form() {};

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


