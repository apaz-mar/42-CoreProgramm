/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:21:59 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/01/07 12:29:07 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "========= Valid construction ==========" << std::endl;
    try
    {
        Bureaucrat a("Alice", 2);
        Bureaucrat b("Bob", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << "\nIncrement Alice" << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;

        std::cout << "\nDecrement Bob" << std::endl;
        b.decrementGrade();                                 //should throw
        std::cout << b << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    

    std::cout << "\n========= Invalid construction ===========" << std::endl;
    try
    {
        Bureaucrat c("Charlie", 0);
        std::cout << c << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat d("David", 151);
        std::cout << d << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }    

    std::cout << "\n========== Copy tests ==========" << std::endl;
    try
    {
        Bureaucrat e("Eva", 10);
        Bureaucrat f = e;           // copy constructor
        Bureaucrat g("George", 50);
        g = e;                      // copy assignment, name must remain
        std::cout << f << std::endl;
        std::cout << g << std::endl;
    }
    
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return (0);
}




