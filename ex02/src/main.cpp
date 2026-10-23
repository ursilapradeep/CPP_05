/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:05:33 by us                #+#    #+#             */
/*   Updated: 2026/10/23 12:37:00 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#include <iostream>

int main()
{
    try
    {
        Bureaucrat br("Sandy", 1);
        ShrubberyCreationForm form("Garden");
        form.beSigned(br);
        form.execute(br);
        //RobotomyRequestForm form2("Robot");
        //PresidentialPardonForm form3("President");
    }
    catch(const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
