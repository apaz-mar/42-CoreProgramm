/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:08:33 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 19:19:08 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "Creating ClapTrap:" << std::endl;
    ClapTrap c("CT");

    std::cout << "\nCreating ScavTrap:" << std::endl;
    ScavTrap s("ST");

    std::cout << "\nCreating FragTrap:" << std::endl;
    FragTrap f("FT");

    std::cout << "\nbasic FragTrap actions:" << std::endl;
    f.attack("Target dummy");
    f.takeDamage(40);
    f.beRepaired(20);
    f.highFivesGuys();

    std::cout << "\nCopy and assignment tests for FragTrap:" << std::endl;
    FragTrap f2(f);
    FragTrap f3;
    f3 = f;

    std::cout << "\nleaving main" << std::endl;
    return (0);
}