/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:33:35 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/10 12:57:04 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>

class Form;

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
        void signForm(Form &form);

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