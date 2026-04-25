/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:57:00 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/25 17:02:29 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Data.hpp"
#include "Serialization.hpp"

Serializer::Serializer()
{}

Serializer::~Serializer()
{}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr)); //interpretiere die Adresse als Zahl
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));  // interpretiere die Zahl wieder als Adresse
}