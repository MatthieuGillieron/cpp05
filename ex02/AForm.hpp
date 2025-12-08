
#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;

#include <iostream>
#include <string>


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

		virtual void execute(Bureaucrat const & executor) const = 0;
};

	std::ostream& operator<<(std::ostream& os, const Form& f);

#endif