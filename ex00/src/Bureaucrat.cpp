/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:52:14 by uvadakku          #+#    #+#             */
/*   Updated: 2026/10/21 12:54:03 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

//Orthodox Canonical Form
Bureaucrat::Bureaucrat():_name("unknown"), _grade(1)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : 
	_name(other._name), _grade(other._grade)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{

	
}

Bureaucrat::~Bureaucrat()
{
	
}
//Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

//getters
std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

//Increment and Decrement member functions
void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	++_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	--_grade;
}

//Exception what()
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

//Overloaded insertion operator
std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	
}
