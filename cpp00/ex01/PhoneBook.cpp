/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:13:28 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/20 16:13:30 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{
    size = 0;
    next = 0;
}

void    PhoneBook::add(const Contact &c)
{
    contacts[next] = c;
    if (size < 8)
        size++;
    next = (next + 1) % 8;
}

int     PhoneBook::count() const
{
    return (size);
}

const   Contact* PhoneBook::at(int idx) const
{
    if (idx < 0 || idx >= size)
        return (0);
    return (&contacts[idx]);
}

std::string PhoneBook::col10(const std::string &s)
{
    if(s.size() > 10)
        return (s.substr(0, 9) + ".");
    // pad for creating a string of spaces before the short string
    std::string pad;
    if (s.size() < 10)
        pad.assign(10 - s.size(), ' ');
    return (pad + s);
}

