/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:41:55 by mg                #+#    #+#             */
/*   Updated: 2025/12/10 14:31:27 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	
	srand(time(NULL)); 

	std::cout << "\n=== FORM REQUIREMENTS ===" << std::endl;

	std::cout << "ShrubberyCreationForm :" << std::endl;
	std::cout << "  - sign   : 145" << std::endl;
	std::cout << "  - execute: 137" << std::endl;

	std::cout << "\nRobotomyRequestForm :" << std::endl;
	std::cout << "  - sign   : 72" << std::endl;
	std::cout << "  - execute: 45" << std::endl;

	std::cout << "\nPresidentialPardonForm :" << std::endl;
	std::cout << "  - sign   : 25" << std::endl;
	std::cout << "  - execute: 5" << std::endl;

	std::cout << "\n=== BUREAUCRAT GRADE ===" << std::endl;
	
	Bureaucrat chef("chef", 1);
	Bureaucrat middle("middle", 72);
	Bureaucrat noob("middle", 148);
	
	std::cout << " - Chef: " << chef.getGrade() << std::endl;
	std::cout << " - Middle: " << middle.getGrade() << std::endl;
	std::cout << " - Noob: " << noob.getGrade() << std::endl;
	
	std::cout << "\n==========TEST============\n" << std::endl;

	ShrubberyCreationForm shrub("A");
    RobotomyRequestForm robo("B");
    PresidentialPardonForm pardon("C");

    std::cout << "\n [ CHEF ]\n";
	std::cout << "\n===== Shrubbery =====\n";
    chef.signForm(shrub);
    chef.executeForm(shrub);

	std::cout << "\n===== Robotomy =====\n";
    chef.signForm(robo);
    chef.executeForm(robo);

	std::cout << "\n===== Presidential =====\n";
    chef.signForm(pardon);
    chef.executeForm(pardon);

	
    std::cout << "\n[ MIDDLE ]\n";
    ShrubberyCreationForm shrub2("A2");
    RobotomyRequestForm robo2("B2");
    PresidentialPardonForm pardon2("C2");

	std::cout << "\n===== Shrubbery =====\n";
    middle.signForm(shrub2);
    middle.executeForm(shrub2);

	std::cout << "\n===== Robotomy =====\n";
    middle.signForm(robo2);
    middle.executeForm(robo2);

	std::cout << "\n===== Presidential =====\n";
    middle.signForm(pardon2);
    middle.executeForm(pardon2);

    std::cout << "\n[ NOOB ]\n";
    ShrubberyCreationForm shrub3("A3");
    RobotomyRequestForm robo3("B3");
    PresidentialPardonForm pardon3("C3");

	std::cout << "\n===== Shrubbery =====\n";
    noob.signForm(shrub3);
    noob.executeForm(shrub3);

	std::cout << "\n===== Robotomy =====\n";
    noob.signForm(robo3);
    noob.executeForm(robo3);

	std::cout << "\n===== Presidential =====\n";
    noob.signForm(pardon3);
    noob.executeForm(pardon3);

    return 0;

}
