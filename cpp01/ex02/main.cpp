/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:27:30 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/23 15:35:40 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main ()
{
    std::string brain = "HI THIS IS BRAIN";

    std::string*    stringPTR = &brain;
    std::string     &stringREF = brain;
    
    // print memory addresses
    std::cout << "Address of brain:      " << &brain << std::endl;
    std::cout << "Address in stringPTR   " << stringPTR << std::endl;
    std::cout << "Address in stringREF   " << &stringREF << std::endl;

    // print values
    std::cout << "Value of brain:        " << brain << std::endl;
    std::cout << "Value via stringPTR    " << *stringPTR << std::endl;
    std::cout << "Value via stringREF    " << stringREF << std::endl;

    return (0);
}