

### AForm

[x] Rendre AForm abstraite -> ``` virtual void execute(Bureaucrat const & executor) const = 0; ```
Rendre AForm virtuel

[x] Ajouter methode Aform -> ``` void checkExecuteRequirements(Bureaucrat const & executor) const; ```
Doit faire :
 - si _isSigned == false → throw
 - si executor.grade > _gradeToExecute → throw

### Bureaucrat

[x] Ajouter methode -> ``` void executeForm(AForm const & form); ```
Doit faire :
 - essayer d’appeler form.execute(*this)
 - afficher un message SUCCESS ou ERROR


### Classes enfant

--- 


## ShrubberyCreationForm

 Créer ShrubberyCreationForm.hpp/.cpp

 Hériter de AForm

 Ajouter target

 Constructeur : grades (145, 137)

 execute() :

 appeler checkExecuteRequirements()

 créer fichier <target>_shrubbery

 écrire ASCII tree