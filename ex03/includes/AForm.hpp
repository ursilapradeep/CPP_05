
#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

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
        virtual ~AForm();
        
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
