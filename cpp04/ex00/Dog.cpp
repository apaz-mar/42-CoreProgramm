/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:34:29 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 21:39:09 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}