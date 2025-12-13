/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:53:59 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/13 21:22:58 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main ()
{
    const Animal* animals[4];

    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n=== Deep copy test ===" << std::endl;

    Dog d1;
    d1.getBrain()->ideas[0] = "I want a bone";

    Dog d2 = d1;

    std::cout << "d1 idea: " << d1.getBrain()->ideas[0] << std::endl;
    std::cout << "d2 idea: " << d2.getBrain()->ideas[0] << std::endl;
    
    d2.getBrain()->ideas[0] = "I want to sleep";
    std::cout << "d1 idea after change " << d1.getBrain()->ideas[0] << std::endl;
    std::cout << "d2 idea after change " << d2.getBrain()->ideas[0] << std::endl; 

    return (0);
}