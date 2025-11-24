/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:58:51 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/23 15:12:16 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : name("") {}          // default empty name

Zombie::Zombie(const std::string &name) : name(name) {}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " is destroyed" << std::endl;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name)
{
    this->name = name;
}