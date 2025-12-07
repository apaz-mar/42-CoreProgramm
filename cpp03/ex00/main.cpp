/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:08:33 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 14:27:59 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    a("Alice");
    ClapTrap    b("Bob");

    ClapTrap c(a);      // copy constructor test
    ClapTrap d;
    d = b;              // assignment test

    a.attack("Bob");
    b.takeDamage(5);
    b.beRepaired(3);

    for (int i = 0; i < 12; ++i)
        a.attack("a dummy target");         // deplete Alice energy

    b.takeDamage(100);          //kill Bob and try to act afterwards
    b.attack("Alice");
    b.beRepaired(10);

    return (0);
}