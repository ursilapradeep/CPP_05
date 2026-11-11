/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:02:04 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/11 11:20:08 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

static void handleForm(Bureaucrat &bureaucrat, AForm *form)
{
    if (form == NULL)
        return;
    bureaucrat.signForm(*form);
    try
    {
        form->execute(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
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
    std::srand(std::time(NULL));
    testIntern();
    return 0;
}
