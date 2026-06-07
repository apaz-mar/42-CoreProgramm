/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:23:48 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/06/05 14:23:48 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>       //getline is here
#include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _rates;                       //once the database is loaded, here are the rates stored, like _rates[date] = rate

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void loadDatabase(const std::string& database);

        void processInput(const std::string& input);
        bool isValidDate(const std::string& date) const;
        bool isValidValue(const double value) const;
        double getRateForDate(const std::string& date, const double value) const;
};

#endif