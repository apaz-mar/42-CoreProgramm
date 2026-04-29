/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:39:53 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/29 22:00:32 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void   iter(T* array, int length, void (*f)(T &))      
{ 
    for (int i = 0; i < length; i++)
        f(array[i]);
    return ;
}

template <typename T>
void   iter(T const* array, int length, void (*f)(T const&))       //to cover const and non-const elements in the iter function
{ 
    for (int i = 0; i < length; i++)
        f(array[i]);
    return ;
}

#endif