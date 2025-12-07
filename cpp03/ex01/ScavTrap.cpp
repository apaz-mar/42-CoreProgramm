/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:47:36 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 15:47:21 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)        // calling base class constructor
{
    std::cout << "ScavTrap name constructor called for " << _name << std::endl;

    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap() : ClapTrap("default")
{
    std::cout << "ScavTrap default constructor called for " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;

    if (this != &other)
    {
        ClapTrap::operator=(other);         //reuse base assignment from claptrap
    }
    return (*this); //return a reference to allow chaining a=b=c
}

void    ScavTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack because of lack of hit points" << std::endl;
        return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack because it's out of energy" << std::endl;
        return ;
    }

    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage " << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}