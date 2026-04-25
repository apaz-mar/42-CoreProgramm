/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 10:39:00 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/25 15:32:48 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

bool ScalarConverter::isInt(const std::string& s)
{
    if (s.empty())
        return (false);
    
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return (false); //it must be something more than just a + or a -
    
    for (; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return (false);
    }

    return (true);
}

bool ScalarConverter::isChar(const std::string& s)
{
    return ((s.length() == 1) && !(isdigit(s[0])));
}

bool ScalarConverter::isFloatPseudo(const std::string& s)
{
    return (s == "nanf" || s == "+inff" || s == "-inff");
}

bool ScalarConverter::isDoublePseudo(const std::string& s)
{
    return (s == "nan" || s == "+inf" || s == "-inf");
}

bool ScalarConverter::isPseudo(const std::string& s)
{
    return (isFloatPseudo(s) || isDoublePseudo(s));
}

bool ScalarConverter::isDecimal(const std::string& s)
{
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;

    bool    hasDot = false;
    bool    hasDigitBefore = false;
    bool    hasDigitAfter = false;

    for (; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            if (hasDot)
                return (false);
            hasDot = true;
        }
        else if (std::isdigit(s[i]))
        {
            if (!hasDot)
                hasDigitBefore = true;
            else
                hasDigitAfter = true;
        }
        else
            return (false);
    }
    return (hasDot && hasDigitBefore && hasDigitAfter);
}

bool ScalarConverter::isFloat(const std::string& s)
{
    if (s == "nanf" || s == "+inff" || s == "-inff")
        return (true);

    if (s.length() < 3) // minimal 0.0f 
        return (false);
    
    if (s[s.length() - 1] != 'f')
        return (false);

    return (isDecimal(s.substr(0, s.length() - 1)));
}

bool ScalarConverter::isDouble(const std::string& s)
{
    if (s == "nan" || s == "+inf" || s == "-inf")
        return (true);

    if (s.length() < 2) // minimal 0.0 
        return (false);

    return (isDecimal(s));
}

Type ScalarConverter::detectType(const std::string& s)
{
    if (isPseudo(s))
        return(PSEUDO);
    if (isInt(s))
        return (INT);
    if (isChar(s))
        return (CHAR);
    if (isFloat(s))
        return (FLOAT);
    if (isDouble(s))
        return (DOUBLE);

    return (INVALID);
}

void ScalarConverter::convert(const std::string& s)
{
    Type t = detectType(s);

    switch(t)
    {
        case PSEUDO:
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;

            if (isFloatPseudo(s))
            {
                std::cout << "float: " << s << std::endl;
                std::cout << "double: " << s.substr(0, s.length() - 1) << std::endl;
            }
            else 
            {
                std::cout << "float: " << s << "f" << std::endl;
                std::cout << "double: " << s << std::endl; 
            }
            break ;
        }
        case INT:
        {
            long value = std::strtol(s.c_str(), NULL, 10);

            // cast to char
            std::cout << "char: ";
            if (value < 0 || value > 127)
                std::cout << "impossible" << std::endl;
            else if (!std::isprint(static_cast<char>(value)))
                std::cout << "Non displayable" << std::endl;
            else
                std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

            // cast to int
            std::cout << "int: ";
            if (value < INT_MIN || value > INT_MAX)
                std::cout << "impossible" << std::endl;
            else
                std::cout << static_cast<int>(value) << std::endl;

            //cast to float
            float f = static_cast<float>(value);
            std::cout << "float: " << f;
            if (f < 1000000 && f > -1000000)
                std::cout << ".0";
            std::cout << "f" << std::endl;

            // cast to double
            double d = static_cast<double>(value);
            std::cout << "double: " << d;
            if (d < 1000000 && d > -1000000)
                std::cout << ".0";
            std::cout << std::endl;
        
            break ;
        }
        case CHAR:
        {
            char c = s[0];

            std::cout << "char: '" << s[0] << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;

            break ;
        }
        case FLOAT:
        {
            float f = std::strtof(s.c_str(), NULL);

            // cast to char
            std::cout << "char: ";
            if (f < 0 || f > 127)
                std::cout << "impossible" << std::endl;
            else if (!std::isprint(static_cast<char>(f)))
                std::cout << "Non displayable" << std::endl;
            else
                std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

            // cast to int
            std::cout << "int: ";
            if (f < INT_MIN || f > INT_MAX || f != f) //isnan(f) nicht erlaubt... die einzige Zahl die nicht gleich selbst ist ist NaN
                std::cout << "impossible" << std::endl;
            else
                std::cout << static_cast<int>(f) << std::endl;

            //cast to float---cout formatiert Zahlen minimal
            std::cout << "float: " << f;
            if (f == static_cast<int>(f) && f < 1000000 && f > -1000000)
                std::cout << ".0";
            std::cout << "f" << std::endl;

            // cast to double
            double d = static_cast<double>(f);
            std::cout << "double: " << d;
            if (d == static_cast<int>(d) && d < 1000000 && d > -1000000)
                std::cout << ".0";
            std::cout << std::endl;
        
            break ;
        }
        case DOUBLE:
        {
            double d = std::strtod(s.c_str(), NULL);

            // cast to char
            std::cout << "char: ";
            if (d < 0 || d > 127)
                std::cout << "impossible" << std::endl;
            else if (!std::isprint(static_cast<char>(d)))
                std::cout << "Non displayable" << std::endl;
            else
                std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

            // cast to int
            std::cout << "int: ";
            if (d < INT_MIN || d > INT_MAX || d != d) //isnan(d) nicht erlaubt... die einzige Zahl die nicht gleich selbst ist ist NaN
                std::cout << "impossible" << std::endl;
            else
                std::cout << static_cast<int>(d) << std::endl;

            //cast to float---cout formatiert Zahlen minimal
            float f = static_cast<float>(d);
            std::cout << "float: " << f;
            if (f == static_cast<int>(f) && f < 1000000 && f > -1000000)
                std::cout << ".0";
            std::cout << "f" << std::endl;

            // cast to double
            std::cout << "double: " << d;
            if (d == static_cast<int>(d) && d < 1000000 && d > -1000000)
                std::cout << ".0";
            std::cout << std::endl;
        
            break ;
        }
        default:
            std::cout << "not subject type" << std::endl;
    }
}
