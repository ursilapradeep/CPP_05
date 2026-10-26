/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:54:00 by uvadakku          #+#    #+#             */
/*   Updated: 2026/10/26 17:13:42 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
    {
        (void)other;
    }
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string Names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    typedef AForm *(Intern::*Creator)(const std::string&);
    Creator creators[3] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == Names[i])
        {
            std::cout << "Intern creates " 
                << formName 
                << std::endl;
            return (this->*creators[i])(target);
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return NULL;
}
