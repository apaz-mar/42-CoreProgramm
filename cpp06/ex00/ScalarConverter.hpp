/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 10:27:04 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/25 15:15:09 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

//for int convert
#include <cstdlib> //for strtol
#include <climits> //for INT_MIN, INT_MAX
#include <cctype>   //for isprint, isdigit

#include <iomanip> //manipulation of io ... for the .0

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

// static gehört zur klasse, nicht zum objekt, wird nicht instanziert (wenn in class methods)
// static in file functions mean they are only available in that file 
class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

        static bool isChar(const std::string& s);
        static bool isInt(const std::string& s);
        static bool isDecimal(const std::string& s);
        static bool isFloat(const std::string& s);
        static bool isDouble(const std::string& s);
        static bool isPseudo(const std::string& s);
        static bool isFloatPseudo(const std::string& s);
        static bool isDoublePseudo(const std::string& s);

        static Type detectType(const std::string& literal);

    public:
        static void convert(const std::string& literal);
};

#endif