/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 12:33:40 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/05/02 22:37:47 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>

class Span
{
    private:
        unsigned int        _range;
        std::vector<int>    _data;
    public:
        Span();
        ~Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        // for adding a range of numbers:
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            unsigned int count = std::distance(begin, end); // distance is a number of elements, not the difference. (iterators)

            if (_data.size() + count > _range)
                throw std::exception();

            _data.insert(_data.end(), begin, end);
        }
};

#endif