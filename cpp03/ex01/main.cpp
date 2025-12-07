/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:08:33 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 15:42:35 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "Creating ScavTrap:" << std::endl;
    ScavTrap s("Sofia");

    std::cout << "\nbasic actions:" << std::endl;
    s.attack("Target dummy");
    s.takeDamage(20);
    s.beRepaired(10);
    s.guardGate();

    std::cout << "\nCopy and assignment tests:" << std::endl;
    ScavTrap copy(s);
    ScavTrap other;
    other = s;

    std::cout << "\nleaving main" << std::endl;
    return (0);
}