/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:20:07 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/23 19:16:55 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     WEAPON_HPP
# define    WEAPON_HPP

#include <string>

class Weapon
{
    private:
       std::string type;
    public:
        Weapon(const std::string &type);
        const std::string &getType() const;
        void setType(const std::string &type);    
    };

#endif