/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:01:49 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/29 22:03:51 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "iter.hpp"
#include <iostream>

void printInt(const int &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3};
    const int arr2[] = {4, 5, 6};

    iter(arr, 3, printInt);
    iter(arr2, 3, printInt);

    return (0);
}