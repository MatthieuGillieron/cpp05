/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:41:55 by mg                #+#    #+#             */
/*   Updated: 2025/12/05 21:06:06 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Constructeurs valides ===" << std::endl;
    Bureaucrat sparrow("Sparrow", 1);
    Bureaucrat jack("Jack", 150);

    std::cout << sparrow << std::endl;
    std::cout << jack << std::endl;


    std::cout << "\n=== Constructeurs invalides ===" << std::endl;
    try 
	{
        Bureaucrat tooHigh("tooHigh", 0);
    } 
	catch (std::exception& e)
	{
        std::cout << e.what() << std::endl;
    }

    try
	{
        Bureaucrat tooLow("tooLow", 151);
    }
	catch (std::exception& e)
	{
        std::cout << e.what() << std::endl;
    }



    std::cout << "\n=== signature valides ===" << std::endl;
    try
	{
		Bureaucrat bob("bob", 1);
		Form formA("FormA", 10, 12);

		bob.signForm(formA);
        std::cout << "\n" << formA << std::endl;
    }
	
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
    }


    std::cout << "\n=== signature invalides ===" << std::endl;
    try
	{
		Bureaucrat boby("boby", 10);
    	Form formB("FormB", 8, 4);

		boby.signForm(formB);
        std::cout << "\n" << formB << std::endl;

       
        std::cout << boby << std::endl;
    }
	
	catch (std::exception& e)
	{
        std::cout << e.what() << std::endl;
    }

    return 0;
}
