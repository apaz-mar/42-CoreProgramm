/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:38:03 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/27 14:38:04 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl 
{
    private:
        void    debug();
        void    info();
        void    warning();
        void    error();
    public:
        Harl();
        ~Harl();
        void    complain(const std::string &level);
};

#endif

