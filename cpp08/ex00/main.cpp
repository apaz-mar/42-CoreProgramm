/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 12:00:44 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/05/02 12:04:48 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Not found" << '\n';
    }

    try
    {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Not found" << '\n';
    }

    return (0);
}
