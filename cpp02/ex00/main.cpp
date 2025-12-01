/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:23:36 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/29 18:30:27 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <iostream>
 #include "Fixed.hpp"

 int  main( void )
 {
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return (0);
 }