
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{

	public:
	
		Intern();
		Intern(const Intern& );
		~Intern();
		Intern& operator=(const Intern& );

		AForm* makeForm(std::string formName, std::string target);

	
};

#endif