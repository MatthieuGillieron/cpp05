/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:49:58 by mg                #+#    #+#             */
/*   Updated: 2025/12/10 13:40:29 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// canonical
//value :
// 25, 5

// methode exec :
//
// - checkRequierement()
// - log : "<target> has been pardoned by Zaphod Beeblebrox.
//

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& val) : AForm(val), _target(val._target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}
	
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecuteRequirements(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

