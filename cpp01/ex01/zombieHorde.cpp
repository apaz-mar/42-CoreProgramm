/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:56:50 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/23 15:00:51 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string &name)
{
    Zombie *horde;
    int     i;

    if (N <= 0)
        return (0);

    horde = new Zombie[N];

    i = 0;
    while (i < N)
    {
        horde[i].setName(name);
        i++;
    }
    return (horde);
}