/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:21:59 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/01/07 21:38:27 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "====== Create bureaucrats ======" << std::endl;
    Bureaucrat high("High", 1);
    Bureaucrat mid("Mid", 50);
    Bureaucrat low("Low", 150);

    std::cout << high << std::endl;
    std::cout << mid << std::endl;
    std::cout << low << std::endl;

    std::cout << "\n======= Creae valid forms ========" << std::endl;
    Form easy("EasyForm", 150, 150);
    Form hard("HardForm", 10, 5);

    std::cout << easy << std::endl;
    std::cout << hard << std::endl;

    std::cout << "\n====== Signing tests ==========" << std::endl;

    std::cout << "\nLow tries to sign HardForm:" << std::endl;
    low.signForm(hard);                             // should fail
    std::cout << hard << std::endl;

    std::cout << "\nHigh tries to sign HardForm:" << std::endl;
    high.signForm(hard);
    std::cout << hard << std::endl;

    std::cout << "\nMid tries to sign EasyForm:" << std::endl;
    mid.signForm(easy);
    std::cout << easy << std::endl;

    std::cout << "\n======= Invalid Form construction ========" << std::endl;
    try
    {
        Form bad1("Bad1", 0, 10);
        std::cout << bad1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        Form bad2("Bad2", 151, 10);
        std::cout << bad2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << '\n';
    }   
    return (0);
}




