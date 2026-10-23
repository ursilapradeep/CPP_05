/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:35:57 by us                #+#    #+#             */
/*   Updated: 2026/10/23 15:29:22 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

AForm::AForm ()
    :_name("Unknown"), 
    _isSigned(false), 
    _gradeToSign(150),
    _gradeToExecute(150)
{
}

AForm::AForm (const AForm &other)
    :_name(other._name),
    _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm () 
{
}

AForm::AForm (std::string name, int gradeToSign, int gradeToExecute)
    :_name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &br)
{
    if (br.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm Exception: Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm Exception: Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << "AForm Name: " << AForm.getName() << std::endl;
    os << "Is Signed: " << (AForm.getIsSigned() ? "Yes" : "No") << std::endl;
    os << "Grade to Sign: " << AForm.getGradeToSign() << std::endl;
    os << "Grade to Execute: " << AForm.getGradeToExecute() << std::endl;
    return os;
}

void AForm::execute(const Bureaucrat &executor)const
{
    if (!_isSigned)
        throw std::runtime_error("AForm Exception: Form is not signed!");
    if (executor.getGrade() > _gradeToExecute)
        throw std::runtime_error("AForm Exception: GradeTooLow Exception!");
}
