/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:19:51 by mg                #+#    #+#             */
/*   Updated: 2025/12/17 10:30:14 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


typedef AForm* (*FormCreator)(const std::string& target);

Intern::Intern()
{}

Intern::Intern(const Intern& val)
{
	(void)val;
}

Intern::~Intern()
{}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}


AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string listForm[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	FormCreator createForm[3] = {createShrubbery, createRobotomy, createPresidential};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == listForm[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return createForm[i](target);
		}
	}
	
	std::cout << "Intern cannot create " << formName << std::endl;
	return nullptr;
}