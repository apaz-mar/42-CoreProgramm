/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:46:27 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/22 18:50:09 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    // Heap zombie
    Zombie *heapZombie = newZombie("Heap");
    heapZombie->announce();
    delete heapZombie;

    // Stack zombie
    randomChump("Stack");

    return (0);
}