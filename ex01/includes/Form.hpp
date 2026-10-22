/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:52:52 by us                #+#    #+#             */
/*   Updated: 2026/10/22 17:03:34 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

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
