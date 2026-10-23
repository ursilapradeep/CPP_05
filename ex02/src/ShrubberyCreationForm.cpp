/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:36:22 by us                #+#    #+#             */
/*   Updated: 2026/10/23 12:49:49 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
: AForm("ShrubberyCreationForm", 145, 137)
{
    _target = "Unknown";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    (void)executor;
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }
    outfile << "        *        " << std::endl;
    outfile << "       ***       " << std::endl;
    outfile << "      *****      " << std::endl;
    outfile << "     *******     " << std::endl;
    outfile << "    *********    " << std::endl;
    outfile << "   ***********   " << std::endl;
    outfile << "  *************  " << std::endl;
    outfile << "        ||        " << std::endl;
    outfile << "        ||        " << std::endl;
    outfile.close();
}
