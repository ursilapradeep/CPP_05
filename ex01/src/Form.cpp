/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:35:57 by us                #+#    #+#             */
/*   Updated: 2026/10/22 16:05:49 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

Form::Form ()
    :_name("Unknown"), 
    _isSigned(false), 
    _gradeToSign(150),
    _gradeToExecute(150)
{
}

Form::Form (const Form &other)
    :_name(other._name),
    _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form () 
{
}

Form::Form (std::string name, int gradeToSign, int gradeToExecute)
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

std::string Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &br)
{
    if (br.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form Exception: Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form Exception: Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form Name: " << form.getName() << std::endl;
    os << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
    os << "Grade to Sign: " << form.getGradeToSign() << std::endl;
    os << "Grade to Execute: " << form.getGradeToExecute() << std::endl;
    return os;
}
