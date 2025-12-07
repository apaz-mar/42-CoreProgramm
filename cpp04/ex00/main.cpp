/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:06:23 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 22:08:12 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Correct animals ===" << std::endl;

    const Animal* meta = new Animal();
    const Animal* i = new Dog();
    const Animal* j = new Cat();

    std::cout << i->getType() << std::endl; // Dog
    std::cout << j->getType() << std::endl; // Cat

    i->makeSound();      // Dog sound
    j->makeSound();      // Cat sound
    meta->makeSound();   // generic Animal sound

    delete meta;
    delete i;
    delete j;

    std::cout << std::endl << "=== Wrong animals ===" << std::endl;

    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << wa->getType() << std::endl;
    std::cout << wc->getType() << std::endl;

    wa->makeSound();    // WrongAnimal sound
    wc->makeSound();    // ALSO WrongAnimal sound (because not virtual!)

    delete wa;
    delete wc;

    std::cout << std::endl << "=== Direct WrongCat ===" << std::endl;

    WrongCat wc2;
    wc2.makeSound();    // Here it will call WrongCat::makeSound, because object type is WrongCat

    return (0);
}