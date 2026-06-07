/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 12:05:30 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/06/06 12:05:30 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }

    std::vector<int> vec;
    std::deque<int> deq;

    PmergeMe sorter;

    for (int i = 1; i < argc; i++)
    {
        int value = sorter.parseAndValidate(argv[i]);

        for (size_t j = 0; j < vec.size(); j++)         //just reject if duplicates
        {
            if (vec[j] == value)
            {
                std::cerr << "Error" << std::endl;
                return (1);
            }
        }

        vec.push_back(value);
        deq.push_back(value);
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
   
    clock_t startVec = clock();         //it returns "clock ticks", 1 million per second
    std::vector<int> sortedVec = sorter.sortContainer(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    std::deque<int> sortedDeq = sorter.sortContainer(deq);
    clock_t endDeq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < sortedVec.size(); i++)
        std::cout << sortedVec[i] << " ";
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec) * 1000000 / CLOCKS_PER_SEC;  //multiplied by a million to show microseconds
    double timeDeq = static_cast<double>(endDeq - startDeq) * 1000000 / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
    
    return (0);
}