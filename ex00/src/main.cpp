/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:26:39 by uvadakku          #+#    #+#             */
/*   Updated: 2026/10/21 11:41:15 by uvadakku         ###   ########.fr       */
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

int main()
{
    try
    {
        Bureaucrat br("Sandy", 2);
        std::cout << br.getName() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    tooHighTest();
    tooLowTest();
    return 0;
}
