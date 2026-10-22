#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Form form("Top Secret", 5, 10);
		Bureaucrat br("Sandy", 2);
		Bureaucrat br2("Doe", 6);
		std::cout << br.getName() << std::endl;
		std::cout << br2.getName() << std::endl;
		br.signForm(form);	
		br2.signForm(form);
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what() << '\n';
	}	
	return 0;
}
