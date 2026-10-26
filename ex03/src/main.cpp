#include "../includes/Intern.hpp"
#include "../includes/Bureaucrat.hpp"

#include <iostream>

static void handleForm(Bureaucrat &bureaucrat, AForm *form)
{
    if (form == NULL)
        return;
    bureaucrat.signForm(*form);
    form->execute(bureaucrat);
    delete form;
}

void testIntern()
{
    std::cout << "----- Intern Test -----" << std::endl;

    Intern intern;

    AForm *f1 = intern.makeForm("shrubbery creation", "home");
    AForm *f2 = intern.makeForm("robotomy request", "Bender");
    AForm *f3 = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm *f4 = intern.makeForm("unknown form", "nobody");

    std::cout << std::endl;

    Bureaucrat boss("Boss", 1);

    handleForm(boss, f1);
    handleForm(boss, f2);
    handleForm(boss, f3);
    delete f4;
}

int main()
{
    testIntern();
    return 0;
}
