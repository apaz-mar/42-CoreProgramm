/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:12:18 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/29 21:37:25 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Whatever.hpp"

#include <iostream>
#include <string>

int main( void ) 
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    int e = 5;
    int f = 5;

    const int& result_min = ::min(e, f);
    std::cout << "result value: " << result_min << std::endl;
    std::cout << "address of e: " << &e << std::endl;
    std::cout << "address of f: " << &f << std::endl;
    std::cout << "address of result: " << &result_min << std::endl;

    int g = 6;
    int h = 6;

    const int& result_max = ::max(g, h);
    std::cout << "result value: " << result_max << std::endl;
    std::cout << "address of g: " << &g << std::endl;
    std::cout << "address of h: " << &h << std::endl;
    std::cout << "address of result: " << &result_max << std::endl;

    return (0);
}
