/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:20:18 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/29 23:04:04 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array         // Array that contains elements of type T
{
    private:
        T*              _data;              //dynamic array storage
        unsigned int    _size;

    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);

        unsigned int size() const;

        T& operator[](unsigned int index);                      //to modify like a[i] = 5;
        const T& operator[](unsigned int index) const;          // to read like const_a[i];
};

#include "Array.tpp"

#endif