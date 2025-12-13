/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:54:08 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/13 21:47:47 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string const &AAnimal::getType() const
{
    return (this->type);
}

// implementaion of makeSound() not necessary for pure virtual functions
//void AAnimal::makeSound() const
//{
//    std::cout << "AAnimal makes a generic sound" << std::endl;
//}