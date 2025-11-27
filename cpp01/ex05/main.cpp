/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:11:28 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/27 16:11:29 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <level>" << std::endl;
        return (1);
    }

    std::string level = av[1];
    harl.complain(level);

    return (0);
}

