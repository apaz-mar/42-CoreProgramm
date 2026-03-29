/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:37:42 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/03/29 13:05:48 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someHiWi;

    AForm* f1 = someHiWi.makeForm("robotomy request", "Bender");
    AForm* f2 = someHiWi.makeForm("shrubbery creation", "garden");
    AForm* f3 = someHiWi.makeForm("presidential pardon", "Sanchez");
    AForm* f4 = someHiWi.makeForm("unknown form", "???");

    Bureaucrat boss("Boss", 1);

    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete (f1);
    }
    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete (f2);
    }
    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete (f3);
    }
    if (f4)
        delete (f4);
    return (0);
}