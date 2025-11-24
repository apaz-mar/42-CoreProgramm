/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:46:27 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/23 15:12:50 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    int     N;
    Zombie* horde;
    int     i;

    N = 5;
    horde = zombieHorde(N, "Horde member");
    if (!horde)
        return (1);
    
    i = 0;
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete [] horde;
    return (0);
}