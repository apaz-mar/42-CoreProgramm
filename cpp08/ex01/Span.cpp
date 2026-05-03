/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:19:32 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/05/02 22:30:09 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"
#include <vector>
#include <exception>
#include <algorithm>

Span::Span() : _range(1)
{
    _data.reserve(1);
}

Span::~Span()
{}

Span::Span(unsigned int N) : _range(N)
{
    _data.reserve(N);   // allocates memory, but doesnt create elements
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_range = other._range;
        this->_data = other._data;
    }
    return (*this);
}

void Span::addNumber(int num)
{
    if(_data.size() >= _range)
        throw std::exception();
    _data.push_back(num);
}

int Span::longestSpan()
{
    if (_data.size() <= 1)
        throw std::exception();
    
    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    
    return (max - min);    
}

int Span::shortestSpan()
{
    if (_data.size() <= 1)
        throw std::exception();

    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];

    for (size_t i = 1; i < tmp.size(); i++)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return (minSpan);  
}

