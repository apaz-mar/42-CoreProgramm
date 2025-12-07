/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:41:06 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 21:43:38 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}