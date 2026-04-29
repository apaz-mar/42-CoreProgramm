/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Start.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:56:38 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/29 21:37:05 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
T const &min(T const &x, T const &y)         // same type everywehere ...int - int then T - T
{
    return ( (x < y) ? x : y );
}

template <typename T>
T const &max(T const &x, T const &y)         
{
    return ( (x > y) ? x : y );
}

template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;

    return ;
}

#endif

