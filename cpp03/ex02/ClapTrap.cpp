/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:24:46 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 15:44:25 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hitPoints(other._hitPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    
    if (this != &other)
    {
        _name           = other._name;
        _hitPoints      = other._hitPoints;
        _energyPoints   = other._energyPoints;
        _attackDamage   = other._attackDamage;
    }
    return (*this); //return a point to allow chaining a=b=c
}

void    ClapTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack because of lack of hit points" << std::endl;
        return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack because it's out of energy" << std::endl;
        return ;
    }

    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage " << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage" << std::endl;
    _hitPoints = _hitPoints - amount;
    if (_hitPoints < 0)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " is already destroyed" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't be repaired because it's destroyed " << std::endl;
        return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't be repaired because it's out of energy " << std::endl;
        return ;
    }
    _energyPoints--;
    _hitPoints = _hitPoints + amount;
    
    std::cout << "ClapTrap " << _name << " repairs itself recovering " << amount << " hit points" << std::endl;
}
