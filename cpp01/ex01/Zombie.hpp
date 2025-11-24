/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:54:02 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/23 14:39:18 by apaz-mar         ###   ########.fr       */
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
        Zombie();                           // default constructor to create them in a row without name
        Zombie(const std::string &name);
        ~Zombie();
        void announce() const;
        void setName(const std::string &name);
};

Zombie* zombieHorde(int N, const std::string &name);

#endif