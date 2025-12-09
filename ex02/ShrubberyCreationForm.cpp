/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:35:19 by mg                #+#    #+#             */
/*   Updated: 2025/12/09 09:46:24 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// === CANONICAL FORM ===

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
 : AForm("ShrubberyCreationForm", 145, 137),  _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& val) : AForm(val)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecuteRequirements(executor);
	std::string nameFile = _target + "_shrubbery";
	std::ofstream file(nameFile);

	file << "       /\\\n";
	file << "      /  \\\n";
	file << "     /____\\\n";
	file << "    /\\    /\\\n";
	file << "   /  \\  /  \\\n";
	file << "  /____\\/____\\\n";
	file << "       ||\n";
	file << "       ||\n";
	file << "       ||\n\n";

	file << "      /\\\n";
	file << "     /  \\\n";
	file << "    /    \\\n";
	file << "   /______\\\n";
	file << "  /\\      /\\\n";
	file << " /  \\    /  \\\n";
	file << "/____\\__/____\\\n";
	file << "      ||\n";
	file << "      ||\n";
	file << "      ||\n\n";

	file << "        /\\\n";
	file << "       /  \\\n";
	file << "      /    \\\n";
	file << "     /______\\\n";
	file << "    /\\      /\\\n";
	file << "   /  \\    /  \\\n";
	file << "  /____\\__/____\\\n";
	file << "        ||\n";
	file << "        ||\n";
	file << "        ||\n";
}