/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:41:55 by mg                #+#    #+#             */
/*   Updated: 2025/12/02 12:46:25 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Constructeurs valides ===" << std::endl;
    Bureaucrat bob("Bob", 1);
    Bureaucrat jack("Jack", 150);

    std::cout << bob << std::endl;
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



    std::cout << "\n=== Increment/decrement valides ===" << std::endl;
    try
	{
		bob.decrementGrade();
        std::cout << bob << std::endl;
    }
	
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
    }
	try
	{
		jack.incrementGrade();
		std::cout << jack << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

    std::cout << "\n=== Increment/decrement invalides ===" << std::endl;
    try
	{
        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << e.what() << std::endl;
    }

    try
	{
        jack.decrementGrade();
        std::cout << jack << std::endl;

        jack.decrementGrade();
        std::cout << jack << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << e.what() << std::endl;
    }

    return 0;
}
