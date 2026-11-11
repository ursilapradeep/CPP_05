/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:57:13 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/11 10:41:26 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form 
{
    private :
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public :
    
        Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        
        Form(std::string name, int gradeToSign, int gradeToExecute);
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        
        void beSigned(const Bureaucrat &bureaucrat);
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

    std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
