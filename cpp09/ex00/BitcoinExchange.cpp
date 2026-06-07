/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:41:58 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/06/05 14:41:58 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>          //for input file stream ifstream()
#include <iostream>
#include <sstream>
#include <algorithm>        //for lower_bound()

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        this->_rates = other._rates;
    return (*this);
}

void BitcoinExchange::loadDatabase(const std::string& database)
{
    std::ifstream file(database.c_str());       //file() needs a c string instead of a c++ std::string
    if (!file.is_open())
    {
        std::cerr << "Error when opening the database." << std::endl;
        return ;
    }
    
    std::string line;

    std::getline(file, line);       //skip the first line (header)

    while (std::getline(file, line))
    {
        std::size_t comma = line.find(',');
        if (comma == std::string::npos)     //no position, so not found
            continue ;

        std::string date = line.substr(0, comma);
        std::string rateStr = line.substr(comma + 1);

        std::stringstream ss(rateStr);
        double rate;
        ss >> rate;

        _rates[date] = rate;
        //std::cout << date << " = " << rate << std::endl;
    }
}

void BitcoinExchange::processInput(const std::string& input)
{
    std::ifstream file(input.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open second database." << std::endl;
        return ;
    }

    std::string line;

    std::getline(file, line);   // skip the header date | value

    while (std::getline(file, line))
    {
        std::size_t sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cerr << "Error: bad input " << "=> " << line << std::endl;
            continue ;
        }

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);

        std::stringstream ss(valueStr);
        double value;
        ss >> value;

        if (!isValidDate(date))
            continue ; 
        if (!isValidValue(value))
            continue ;   
        getRateForDate(date, value);       
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (month > "12" || day > "31")
        std::cerr << "Error: bad input " << "=> " << date << std::endl;
    return (true);
}

bool BitcoinExchange::isValidValue(const double value) const
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }
    else if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (false);
    }
    return (true);
}

double BitcoinExchange::getRateForDate(const std::string& date, const double value) const
{
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);        //lower_bound finds the lowest value of all the values ahead

    if (it == _rates.end() || it->first != date)        //it->first is the lower bound date if the date is missing, so different than date
    {
        if (it == _rates.begin())               //if the date is previous to all pairs, not possible to get a previous value. Following values not allowed; also doesnt make sense to assign a future value
        {
            std::cerr << "Error: no rate available for date => " << date << std::endl;
            return (0);
        }
        --it;       // according to subject, when date missing, the alternative must be below date; lower_bounds gives one above.
    }

    double result = it->second * value; 

    std::cout << date << " => " << value << " = " << result << std::endl;

    return (result);
}



