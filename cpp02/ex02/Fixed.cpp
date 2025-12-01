/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:06:00 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/01 23:59:24 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>  //for roundf

const int Fixed::_fractionalBits = 8;       // 8 as per subject

Fixed::Fixed() : _rawBits(0)                // Each object hast its own rawBits, therefore initialized in the constructor initializer list
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = static_cast<int>(roundf(f * (1 << _fractionalBits)));    // store f as a fixed-point by multiplying by the scale (256), rounding, and saving the result as an int
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawBits);
}

void    Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

int     Fixed::toInt(void) const                    //to get it back, because it was stored multiplying it by fractionalBits
{
    return (_rawBits >> _fractionalBits);
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(_rawBits) / static_cast<float>(1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return (os);
}

//EX02
bool    Fixed::operator>(const Fixed &other) const
{
    return (_rawBits > other._rawBits);
}

bool    Fixed::operator<(const Fixed &other) const
{
    return (_rawBits < other._rawBits);
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return (_rawBits >= other._rawBits);
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return (_rawBits <= other._rawBits);
}

bool    Fixed::operator==(const Fixed &other) const
{
    return (_rawBits == other._rawBits);
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return (_rawBits != other._rawBits);
}

//arithmetic operations with floats are ok because they are more precise than fixed-point
Fixed   Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

//increments: Prefix with reference because it modifies the object. Postfix without reference because it gives a copy of the old object
//Prefix:
Fixed   &Fixed::operator++()
{
    _rawBits = _rawBits + 1;
    return (*this);
}

Fixed   &Fixed::operator--()
{
    _rawBits = _rawBits - 1;
    return (*this);
}

//Postfix:
Fixed   Fixed::operator++(int)
{
    Fixed   old(*this);     //copy
    ++(*this);
    return (old);
}

Fixed   Fixed::operator--(int)
{
    Fixed   old(*this);
    --(*this);
    return (old);
}

// Implementation of max and min
//Non-const references
Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

//Const references
const Fixed   &Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed   &Fixed::max(const Fixed &a, const Fixed &b)
{
    return ((a > b) ? a : b);
}