/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:17:13 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/23 19:53:48 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA  //takes a weapon in its constructor, always armed
{
    private:
        std::string name;
        Weapon      &weapon;
    
    public:
        HumanA(const std::string &name, Weapon &weapon);
        void    attack() const;
};

# endif