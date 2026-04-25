/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 10:49:44 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/25 10:57:41 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    ScalarConverter::convert(argv[1]);
    return(0);
}
