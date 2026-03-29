/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:21:59 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/03/29 13:14:57 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib> //for rand
#include <ctime>

int main()
{
    std::srand(std::time(0));        //std::time(0) returns the current time in seconds since 1970, so srand is always different
    
    std::cout << "====== Create bureaucrats ======" << std::endl;
    Bureaucrat high("High", 1);
    Bureaucrat mid("Mid", 50);
    Bureaucrat low("Low", 150);

    std::cout << high << std::endl;
    std::cout << mid << std::endl;
    std::cout << low << std::endl;

    std::cout << "\n======= Create forms ========" << std::endl;
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Sanchez");

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n====== Execute unsigned forms ==========" << std::endl;
    high.executeForm(shrub);
    high.executeForm(robot);
    high.executeForm(pardon);

    std::cout << "\n======= Sign tests ========" << std::endl;
    std::cout << "\nLow tries to sign shrubbery:" << std::endl;
    low.signForm(shrub);

    std::cout << "\nMid tries to sign robotomy:" << std::endl;
    mid.signForm(robot);

    std::cout << "\nHigh tries to sign pardon:" << std::endl;
    high.signForm(pardon);

    std::cout << "\nForms after signing attempts:" << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n============Execute with different grades================" << std::endl;
    std::cout << "\nLow tries to execute shrubbery:" << std::endl;
    low.executeForm(shrub);

    std::cout << "\nMid tries to execute shrubbery:" << std::endl;
    mid.executeForm(shrub);

    std::cout << "\nHigh tries to execute robotomy twice:" << std::endl;
    high.executeForm(robot);
    high.executeForm(robot);

    std::cout << "\nMid tries to execute pardon:" << std::endl;
    mid.executeForm(pardon);

    std::cout << "\nHigh tries to execute pardon:" << std::endl;
    high.executeForm(pardon);

    std::cout << "\n========End of tests=======" << std::endl;

    return (0);
}




