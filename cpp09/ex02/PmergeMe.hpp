/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:56:48 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/06/06 11:56:48 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <utility>          // for std::pair
#include <iostream>
#include <string>
#include <cstdlib>          // for atoi
#include <sstream>
#include <ctime>


class PmergeMe
{
    private:
        std::vector< std::pair<int, int> > sortPairsBySecond(std::vector< std::pair<int, int> > pairs);
        std::vector< std::pair<int, int> > merge(std::vector< std::pair<int, int> > leftPairs, std::vector< std::pair<int, int> > rightPairs);

        template <typename Container>
        Container insertPending(std::vector< std::pair<int, int> > pairs, int leftover);

        template <typename Container>
        typename Container::iterator binaryInsertPosition(typename Container::iterator begin, typename Container::iterator end, int value);

        template <typename Container>
        typename Container::iterator findPartner(Container& mainChain, int partner);

        std::vector<size_t> buildJacobsthalOrder(size_t n);

        template <typename Container>
        bool isSorted(const Container& cont);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        int parseAndValidate(char* arg);

        template <typename Container>
        Container sortContainer(Container cont);
};

template <typename Container>
Container PmergeMe::sortContainer(Container cont)
{
    std::vector< std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < cont.size(); i = i + 2)
    {
        int a = cont[i];
        int b = cont[i + 1];

        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    int leftover = -1;
    if (cont.size() % 2 != 0)
        leftover = cont.back();

    //for (size_t i = 0; i < pairs.size(); i++)
    //    std::cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
    //if (leftover != -1)
    //  std::cout << "leftover = " << leftover;
    //std::cout << std::endl;

    pairs = sortPairsBySecond(pairs);

    //for (size_t i = 0; i < pairs.size(); i++)
    //    std::cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
    //if (leftover != -1)
    //  std::cout << "leftover = " << leftover;
    //std::cout << std::endl;

    Container finalChain = insertPending<Container>(pairs, leftover);

    //std::cout << "Final chain is sorted: " << isSorted(finalChain) << std::endl;
    return (finalChain);
}

template <typename Container>
bool PmergeMe::isSorted(const Container& cont)
{
    for (size_t i = 1; i < cont.size(); i++)
    {
        if (cont[i - 1] > cont[i])
            return (false);
    }
    return (true);
}

template <typename Container>
Container PmergeMe::insertPending(std::vector< std::pair<int, int> > pairs, int leftover)
{
    Container mainChain;
    Container pending;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        pending.push_back(pairs[i].first);
        mainChain.push_back(pairs[i].second);
    }

    std::vector<size_t> order = buildJacobsthalOrder(pending.size());

    //for (size_t i = 0; i < order.size(); i++)
    //    std::cout << order[i] << " ";
    //std::cout << std::endl;

    for (size_t k = 0; k < order.size(); k++)
    {
        size_t j = order[k];
        
        int partner = pairs[j].second;      // save the pair before the index moves. Search only until the bigger element of the pair.
        typename Container::iterator limit = findPartner<Container>(mainChain, partner);
        if (limit == mainChain.end())
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }

       typename Container::iterator pos = binaryInsertPosition<Container>(mainChain.begin(), limit, pending[j]);

        mainChain.insert(pos, pending[j]);
    }

    if (leftover != -1)
    {
        typename Container::iterator pos = binaryInsertPosition<Container>(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(pos, leftover);
    }
    return (mainChain);
}

template <typename Container>
typename Container::iterator PmergeMe::findPartner(Container& mainChain, int partner)
{
    for (typename Container::iterator it = mainChain.begin(); it !=  mainChain.end(); ++it)
    {
        if (*it == partner)
            return (it);
    }
    return (mainChain.end());
}

template <typename Container>
typename Container::iterator PmergeMe::binaryInsertPosition(typename Container::iterator begin, typename Container::iterator end, int value)
{
    while (begin < end)
    {
        typename Container::iterator mid = begin + (end - begin) / 2;

        if (value < *mid)
            end = mid;
        else
            begin = mid + 1;
    }
    return (begin);
}

#endif