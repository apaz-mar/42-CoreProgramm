/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:08:23 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/05/02 22:46:42 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"
#include <iostream>

int main()
{
    // subject tests
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl << std::endl;

    // additional tests
    Span sp2 = Span(10);

    sp2.addNumber(6);
    sp2.addNumber(2);

    std::vector<int> extra;
    extra.push_back(17);
    extra.push_back(9);
    extra.push_back(10);

    sp2.addNumbers(extra.begin(), extra.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    try
    {
        std::vector<int> tooMuch(10, 20);           //ten elements of value 20
        sp2.addNumbers(tooMuch.begin(), tooMuch.end());         
    }
    catch(const std::exception& e)
    {
        std::cerr << "Cannot add range: Span is full or too small" << '\n' << '\n';
    }

    std::cout << "----- Stress test ------" << std::endl;
    try
    {
        Span big(10000);
        std::vector<int> values;

        for (int i = 0; i < 10000; i++)
            values.push_back(i * 2);

        big.addNumbers(values.begin(), values.end());

        std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span: " << big.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception in stress test" << '\n';
    }
    return (0);
}