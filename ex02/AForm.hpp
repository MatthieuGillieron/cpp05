
#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;

#include <iostream>
#include <string>


class AForm
{

	private:

		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;

	public:

		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm&);
		~AForm();
		AForm& operator=(const AForm&);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);
		void checkExecuteRequirements(Bureaucrat const & executor) const;

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

		class FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		virtual void execute(Bureaucrat const & executor) const = 0;
};

	std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif