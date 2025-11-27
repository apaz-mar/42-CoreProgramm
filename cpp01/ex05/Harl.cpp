/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:14:34 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/27 16:14:36 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
           "pickle-specialketchup burger. I really do!" << std::endl; 
}

void    Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money."
           " You didn’t put enough bacon in my burger!" << std::endl; 
}

void    Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free."
           " I’ve been coming for years..." << std::endl; 
}

void    Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; 
}

void    Harl::complain(const std::string &level)
{
    // Pointer to a function in Harl is: void (Harl::*)(), here given a name to simplify
    typedef void (Harl::*HarlMemFn)();

    HarlMemFn actions[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    //parallel array for the indexes in actions
    const std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    //calling the corresponding member function pointers
    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
        {
            (this->*actions[i])();
            return ;
        }
    }

    // if no match:
    std::cout << "Probably complaining about insignificant problems" << std::endl;
}
