/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:45:17 by uvadakku          #+#    #+#             */
/*   Updated: 2026/10/26 15:53:31 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    private :
        AForm *createShrubberyCreationForm(const std::string &target);
        AForm *createRobotomyRequestForm(const std::string &target);
        AForm *createPresidentialPardonForm(const std::string &target);
        public :
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &name, const std::string &target);
};
#endif