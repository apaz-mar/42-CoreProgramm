/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 13:31:06 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/06/06 13:31:06 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return (*this);
}

int PmergeMe::parseAndValidate(char* arg)   //stringstream safer than atoi with non-digits. Just beware "123abc" with ss.eof()
{
    std::stringstream ss(arg);
    int value;

    if ((!(ss >> value) || !ss.eof() || value <= 0))
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    return (value);
}

std::vector< std::pair<int, int> > PmergeMe::sortPairsBySecond(std::vector< std::pair<int, int> > pairs)      // check by halves
{
    if (pairs.size() <= 1)
        return (pairs);
    
    size_t mid = pairs.size() / 2;

    std::vector< std::pair<int, int> > leftPairs(pairs.begin(), pairs.begin() + mid);    
    std::vector< std::pair<int, int> > rightPairs(pairs.begin() + mid, pairs.end());

    leftPairs = sortPairsBySecond(leftPairs);
    rightPairs = sortPairsBySecond(rightPairs);
    pairs = merge(leftPairs, rightPairs);

    return (pairs);
}

std::vector< std::pair<int, int> > PmergeMe::merge(std::vector< std::pair<int, int> > leftPairs, std::vector< std::pair<int, int> > rightPairs)
{
    size_t i = 0;
    size_t j = 0;

    std::vector< std::pair<int, int> > result;

    while(i < leftPairs.size() && j < rightPairs.size())
    {
        if (leftPairs[i].second < rightPairs[j].second)
        {
            result.push_back(leftPairs[i]);
            i++;
        }
        else
        {
            result.push_back(rightPairs[j]);
            j++;
        }
    }

    //if any side still has elements:
    while (i < leftPairs.size())
    {
        result.push_back(leftPairs[i]);
        i++;
    }

    while (j < rightPairs.size())
    {
        result.push_back(rightPairs[j]);
        j++;
    }

    return (result);
}

std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t n) //0, 2, 1, 4, 3, 10, 9, 8, 7, 6, 5 ...     f[n + 1] = f[n] + 2*f[n-1]
{
    std::vector<size_t> order;          //it creates an empty vector
    if (n == 0)
        return (order);

    order.push_back(0);

    size_t prev = 1;
    size_t curr = 3;
    
    while (order.size() < n)
    {
        size_t limit = curr;
        if (limit > n)
            limit = n;

        for (size_t i = limit; i > prev; --i)
            order.push_back(i - 1);

        size_t next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return (order);
}





