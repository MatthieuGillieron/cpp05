
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

//Form() : _isSigned(false), _name("Default"), _gradeToSign(1), _gradeToExecute(1)

class Form
{

	private:

		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;

	public:

		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form&);
		~Form();
		Form& operator=(const Form&);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);


		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};


};

	std::ostream& operator<<(std::ostream& os, const Form& f);

#endif