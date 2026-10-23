/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:36:22 by us                #+#    #+#             */
/*   Updated: 2026/10/23 15:36:22 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("Unknown")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
: AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);

    std::cout << "Drilling noises..." << std::endl;

    if (std::rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << _target << " robotomization failed." << std::endl;
    }
}
