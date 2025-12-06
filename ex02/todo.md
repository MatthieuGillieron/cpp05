

### AForm

[ ] Rendre AForm abstraite -> ``` virtual void execute(Bureaucrat const & executor) const = 0; ```
Rendre AForm virtuel

[ ] Ajouter methode Aform -> ``` void checkExecuteRequirements(Bureaucrat const & executor) const; ```
Doit faire :
 - si _isSigned == false → throw
 - si executor.grade > _gradeToExecute → throw

### Bureaucrat

[ ] Ajouter methode -> ``` void executeForm(AForm const & form); ```
Doit faire :
 - essayer d’appeler form.execute(*this)
 - afficher un message SUCCESS ou ERROR


### Classes enfant

....