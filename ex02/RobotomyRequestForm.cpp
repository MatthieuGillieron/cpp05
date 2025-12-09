/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:39:03 by mg                #+#    #+#             */
/*   Updated: 2025/12/09 14:22:41 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// TODO

// canonique form
// value defini : 
// grade to sign -> 75
// grade to exec -> 45
// name -> "RobotomyRequestForm"


// methode execute 
// - checkRequierment -> call function for that
// - bruit de perceuse -> log like "BZzzzz.."
// - random luck -> 50% reuissite


RobotomyRequestForm::RobotomyRequestForm() : AForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 75, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& val) : AForm(val), _target(val._target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecuteRequirements(executor);
	int random = rand() % 2;

	std::cout << "BZZzzz..." << std::endl;
	if (random == 0)
	{
		std::cout << _target << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "the robotomized failed on " << _target << std::endl;
	}
}

