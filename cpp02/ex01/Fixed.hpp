/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:40:03 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/30 16:41:13 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _rawBits;           // _in front to distinguish private member variables from parameters
        static const int    _fractionalBits;    // static because only one fractionalBits is shared by all Fixed objects

    public:
        //Orthodox canonical form
        Fixed();                                // Default constructor
        Fixed(const Fixed &other);              // Copy constructor
        Fixed &operator=(const Fixed &other);    // Copy assignment
        ~Fixed();                               // Default destructor
        
        Fixed(const int n);                      // int constructor
        Fixed(const float f);                    // float constructor

        int                 getRawBits(void) const;
        void                setRawBits(int const raw);

        int                 toInt(void) const;
        float               toFloat(void) const;
};

// Overload (new version of an operator) of <<, so that the call of a class is valid
std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif