/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:41:55 by mg                #+#    #+#             */
/*   Updated: 2025/12/17 11:25:48 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int main()
{
	
	srand(time(NULL)); 
	try
	{
		Intern elStagerio;
		Bureaucrat Jefe("Jefe", 1);

		std::cout << "\n=== FORM VALID ===" << std::endl;

		AForm* shrubbery = elStagerio.makeForm("shrubbery creation", "Outside");
		AForm* robotomy = elStagerio.makeForm("robotomy request", "Cat");
		AForm* pardon = elStagerio.makeForm("presidential pardon", "Gringo");

		std::cout <<  "\n";

		if (shrubbery)
        {
            Jefe.signForm(*shrubbery);
            Jefe.executeForm(*shrubbery);
			std::cout <<  "\n";
        }


        if (robotomy)
        {
            Jefe.signForm(*robotomy);
            Jefe.executeForm(*robotomy);
			std::cout <<  "\n";
        }

        if (pardon)
        {
            Jefe.signForm(*pardon);
        	Jefe.executeForm(*pardon);
			std::cout <<  "\n";
        }

        std::cout << "\n=== UNKNOW FORM NAME ===" << std::endl;

     	AForm* unknown = elStagerio.makeForm("Shrek", "castle");
		
        if (!unknown)
            std::cout << "No form created for invalid request." << std::endl;
        delete shrubbery;
        delete robotomy;
        delete pardon;
        delete unknown; // ne fait rien si pointeur nul

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
    return 0;

}
