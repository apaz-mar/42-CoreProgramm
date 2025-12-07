/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:51:35 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/07 22:23:32 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        ~WrongAnimal();                 //not virtual

        WrongAnimal &operator=(const WrongAnimal &other);

        std::string const &getType() const;
        void makeSound() const;         //not virtual
};

#endif