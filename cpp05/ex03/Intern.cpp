/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:00:48 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/03/29 13:09:56 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern copy assignment constructor called" << std::endl;
    (void)other;
    return (*this);
}

AForm* createShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* createRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm* createPardon(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3];
    forms[0] = "shrubbery creation";
    forms[1] = "robotomy request";
    forms[2] = "presidential pardon";
    
    // array of function pointers that take std::string and return AForm*
    AForm* (*creators[3])(std::string);
    creators[0] = createShrubbery;
    creators[1] = createRobotomy;
    creators[2] = createPardon;

    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (creators[i](target));
        }
    }

    std::cout << "Intern could not find form " << name << std::endl;
    return (NULL);
}
