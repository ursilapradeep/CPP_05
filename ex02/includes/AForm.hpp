/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:59:10 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/11 10:46:29 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
    private :
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public :
    
        AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        ~AForm();
        
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &executor) const;
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

    std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif
