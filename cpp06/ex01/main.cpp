/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:04:19 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/25 17:08:17 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Data.hpp"
#include "Serialization.hpp"

#include <iostream>

int main()
{
    Data data;

    data.id = 42;
    data.name = "Aaron";

    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);
    Data* ptr2 = Serializer::deserialize(raw);

    std::cout << "Original ptr: " << ptr << std::endl;
    std::cout << "Raw value: " << raw << std::endl;
    std::cout << "New ptr: " << ptr2 << std::endl;

    std::cout << "Same address? " << (ptr == ptr2) << std::endl;

    std::cout << "Data: " << ptr2->id << ", " << ptr2->name << std::endl;

    return (0);
}
