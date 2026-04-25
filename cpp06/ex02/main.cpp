/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:18:54 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/25 19:20:32 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Identify.hpp"

int main()
{
    std::srand(std::time(NULL));

    Base* ptr = generate();

    identify(ptr);
    identify(*ptr);
    
    delete ptr;

    return (0);
}