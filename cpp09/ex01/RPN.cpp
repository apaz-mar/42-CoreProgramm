/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:10:29 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/06/05 20:10:29 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->_stack = other._stack;
    return (*this);
}

// RPN works like a stack. When an operator appears, takes the two upmost numbers, computes and pops them, push result
void RPN::calculate(const std::string& expression)
{
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)         // the stringstream separates itself elements by empty spaces
    {
        if (isNumber(token))
            _stack.push(token[0] - '0');
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return ;
            }

            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            int result = apply(a, b, token);
            _stack.push(result);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            exit (1);
        }
    }
    if (_stack.size() != 1)
        {
            std::cerr << "Error" << std::endl;
            exit (1);
        }
    std::cout << _stack.top() << std::endl;

    return ;
}

bool RPN::isNumber(const std::string& token)
{
    if (token.length() == 1 && token[0] >='0' && token[0] <= '9')
        return (true);
    return (false);
}

bool RPN::isOperator(const std::string& token)
{
    if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        return (true);
    return (false);
}

int RPN::apply(int a, int b, std::string token)
{
    if (token[0] == '+')
        return (a + b);

    else if (token[0] == '-')
        return (a - b);

    else if (token[0] == '*')
        return (a * b);

    else if (token[0] == '/')
    {
        if (b != 0)
            return (a / b);
        else
        {
            std::cerr << "Error" << std::endl;
            exit (1);
        }            
    }

    else
    {
        std::cerr << "Error" << std::endl;
        exit (1);
    }
}

