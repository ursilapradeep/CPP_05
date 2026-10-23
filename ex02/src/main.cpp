/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:05:33 by us                #+#    #+#             */
/*   Updated: 2026/10/23 16:26:06 by us               ###   ########.fr       */
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

	ShrubberyCreationForm form("Graden");
	Bureaucrat br("Doe", 140);

	signFromTest(br, form);
	executeFormTest(br, form);
}

int main()
{
	testShrubberyCreationForm();
	return 0;
}
