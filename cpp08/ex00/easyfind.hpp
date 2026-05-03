/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 10:57:14 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/05/02 12:32:59 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::exception();

    return (it);
}

#endif