#include "../includes/Bureaucrat.hpp"
#include <iostream>

void incrementTest()
{
    try
    {
        Bureaucrat br("Sandy", 3);
        std::cout << br.getName() << std::endl;	
        br.incrementGrade();
        br.incrementGrade();
        br.incrementGrade();
    }
    catch(const Bureaucrat::GradeTooHighException& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}

void tooHighTest()
{
	try
	{
		Bureaucrat br("Sandy", -11);
		std::cout << br.getName() << std::endl;	
	
	}
	catch(const Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << '\n';
	}	
}

void tooLowTest()
{
	try
	{
		Bureaucrat br("Sandy", 200);
		std::cout << br.getName() << std::endl;	
	
	}
	catch(const Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << '\n';
	}	
}

int main()
{
	try
	{
		Bureaucrat br("Sandy", 2);
		std::cout << br.getName() << std::endl;	
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what() << '\n';
	}	
    incrementTest();
	tooHighTest();
	tooLowTest();
	return 0;
}
