#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n === Valid Construction === \n"

	try {
		Bureaucrat high("Alice", 1);
		std::cout << "High" << "\n";
		Bureaucrat low("Bob", 150);
		std::cout << "Low" << "\n";
	}
	//Because exceptions in C++ do not print themselves
	/* const std::exception &e
	avoids copying the exception
guarantees the object exists
gives clean syntax (e.what())
 */
	catch (const std::exception &e) 
	{
		std::cout << "construction failed : "<< e.what()  <<  "\n"; //To get the human‑readable message, you must call the method: what() → returns the message
	}

	std::cout << " \n === Invalid Construction ===\n"
	try 
	{
		Bureaucrat toolowgrade("Nick", 0);
		std::cout << "Too Low Grade" << "\n";
	} catch (const std::exception &e) 
	{
		std::cout << "Caught (grade 0): "<<e.what() << "\n";
	}
	try
	{
		Bureaucrat tooHighgrade("Lara", 151);
		std::cout << "Too High Grade" << "\n";
	}
	catch (const std::exception &e) 
	{
		std::cout << "Caught (grade 151): "<<e.what() << "\n";
	}
	std::cout << "\n === Increment Boundary Test ===\n";
	try
	{
		Bureaucrat maxgrade("MaxGrade", 1);
		std::cout << maxGrade << " ->increment \n";
		maxGrade.incrementGrade();
	} 
	catch (const std::exception &e) 
	{
		std::cout << "Increment at grade 1 threw" << e.what() << "\n";
	}

	std::cout << "\n === Decrement Boundary Test ===\n";
	try
	{
		Bureaucrat minGrade("MinGrade", 150);
		std::cout << minGrade << " -> decrement \n";
		minGrade.decrementGrade();
	} 
	catch (const std::exception &e) 
	{
		std::cout << "Decrement at grade 150 threw" << e.what() << "\n";
	}
	std::cout << "\n ====Normal Grade changes ==== \n"
	try
	{
		Bureaucrat mid("Mid", 42)
		std::cout << mid << "\n";
		
		mid.incrementGrade();
		std::cout << "After increment: " << mid << "\n"; 
		
		mid.decrementGrade();
  std::cout << "After decrement: " << mid << "\n";
	}
	catch (const std::exception& e) {
  std::cout << "Mid operations failed: " << e.what() << "\n";
	}
	return 0;
}
