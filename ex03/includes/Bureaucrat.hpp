/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:01:08 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/11 10:51:39 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
    private :
        const std::string _name;
        int _grade;

    public :
        // Orthodox Canonical Form
        Bureaucrat();
        Bureaucrat (const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        // Parameterized constructor
        Bureaucrat (std::string name, int grade);
        // getters
        std::string getName() const;
        int getGrade() const;

        // member functions
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);

        // Exception classes
        class GradeTooHighException : public std::exception
        {
            public :
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public :
                const char *what() const throw();
        };
};

#endif