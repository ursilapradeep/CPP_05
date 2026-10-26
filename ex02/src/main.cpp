/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:05:33 by us                #+#    #+#             */
/*   Updated: 2026/10/26 15:01:59 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#include <iostream>

void signFromTest(Bureaucrat &br, AForm &form)
{
    try
    {
        br.signForm(form);
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}

void executeFormTest(Bureaucrat &br, AForm &form)
{
    try
    {
        form.execute(br);
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}

void testShrubberyCreationForm()
{
	ShrubberyCreationForm form("Home");
	Bureaucrat br("Doe", 140);
    
    ShrubberyCreationForm form2("office");
	Bureaucrat br2("Dua", 137);
	signFromTest(br, form);
	executeFormTest(br, form);
	signFromTest(br2, form2);
	executeFormTest(br2, form2);
}

void testRobotomyRequestForm()
{
    RobotomyRequestForm form("Target");
    Bureaucrat br("Joe", 50);

    signFromTest(br, form);
    executeFormTest(br, form);
}

void testPresidentialPardonForm()
{
    PresidentialPardonForm form("Target");
    Bureaucrat br("Jane", 20);

    signFromTest(br, form);
    executeFormTest(br, form);
}

int main()
{
	testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
	return 0;
}
