/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:34:29 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/13 22:00:24 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Dog allocates a Brain in constructor, deletes its Brain in destructor. Copy constructor allocates a new Brain, Assignment copies Brain contents
Dog::Dog() : brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    brain = new Brain(*other.brain);            //copy of the content for deep copy
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        brain = new Brain(*other.brain);            //copy of the content for deep copy
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return (brain);
}