/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:26:39 by uvadakku          #+#    #+#             */
/*   Updated: 2026/10/26 10:59:38 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>

void  tooHighTest()
{
    std::cout << "Invalid Test: Too High Grade" << std::endl;
    try
    {
        Bureaucrat br("Sandy", 200);
        std::cout << br.getName() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: "<< ex.what() << std::endl;  
    }
}

void  tooLowTest()
{
    std::cout << "Invalid Test: Too Low Grade" << std::endl;
    try
    {
        Bureaucrat br("Sandy", -15);
        std::cout << br.getName() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: "<< ex.what() << std::endl;  
    }
}

void  validTest()
{
    std::cout << "Valid Test" << std::endl;
    try
    {
        Bureaucrat br("Sandy", 75);
        std::cout << br << std::endl;
        br.incrementGrade();
        std::cout << "After increment: " << br << std::endl;
        br.decrementGrade();
        std::cout << "After decrement: " << br << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}

int main()
{
    validTest();
    tooHighTest();
    tooLowTest();
    return 0;
}
