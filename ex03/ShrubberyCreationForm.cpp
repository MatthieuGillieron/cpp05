/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:35:19 by mg                #+#    #+#             */
/*   Updated: 2025/12/09 13:46:31 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// === CANONICAL FORM ===

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
 : AForm("ShrubberyCreationForm", 145, 137),  _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& val) : AForm(val), _target(val._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecuteRequirements(executor);
	std::string nameFile = _target + "_shrubbery";
	std::ofstream file(nameFile);

	if (!file.is_open())
	    throw std::runtime_error("Cannot create shrubbery file");


	file << "        *	\n";
	file << "       /-\\\n";
	file << "      /_*_\\\n";
	file << "     /*-_*_\\\n";
	file << "    /*__-_*_\\\n";
	file << "   /-_*__*_-_\\\n";
	file << "  /_-_*_-__*-_\\\n";
	file << "       ||\n";
	file << "       ||\n";
	file << "       ||\n\n";

}