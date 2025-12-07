/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:36:11 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 18:56:16 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)        // calling base class constructor
{
    std::cout << "FragTrap constructor called for " << _name << std::endl;

    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap() : ClapTrap("default")
{
    std::cout << "FragTrap default constructor called for " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;

    if (this != &other)
    {
        ClapTrap::operator=(other);         //reuse base assignment from claptrap
    }
    return (*this); //return a reference to allow chaining a=b=c
}

void    FragTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " can't attack because of lack of hit points" << std::endl;
        return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " can't attack because it's out of energy" << std::endl;
        return ;
    }

    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage " << std::endl;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}