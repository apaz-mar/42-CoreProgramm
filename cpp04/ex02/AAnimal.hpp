/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:14:32 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/13 21:48:17 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal();
        AAnimal(const AAnimal &other);
        virtual ~AAnimal();

        AAnimal &operator=(const AAnimal &other);

        std::string const &getType() const;
        virtual void makeSound() const = 0;         //= 0 makes it abstract, not possible to create an AAnimal object
};

#endif