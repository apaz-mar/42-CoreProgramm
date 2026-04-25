/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:28:34 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/25 16:45:45 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h> // for uintptr_t
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);    
};

#endif