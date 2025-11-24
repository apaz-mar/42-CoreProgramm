/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:54:02 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/22 18:18:59 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     ZOMBIE_HPP
# define    ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie(const std::string &name);
        ~Zombie();
        void announce() const;
};

Zombie* newZombie(const std::string &name);
void    randomChump(const std::string &name);

#endif