/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:20:57 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/23 20:07:52 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB  //does not take the Weapon in the constructor and can be null, may or may not have a weapon
{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(const std::string &name);
        void setWeapon(Weapon &weapon);
        void attack() const;
};

#endif