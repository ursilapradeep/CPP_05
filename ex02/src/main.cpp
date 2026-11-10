/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:00:10 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/10 17:50:26 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

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
	Bureaucrat br2("Damon", 137);
	signFromTest(br, form);
	executeFormTest(br, form);
	signFromTest(br2, form2);
	executeFormTest(br2, form2);
}

void testRobotomyRequestForm()
{
    RobotomyRequestForm form("Target");
    Bureaucrat br("Joe", 45);

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
	std::srand(std::time(NULL));
	testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
	return 0;
}
