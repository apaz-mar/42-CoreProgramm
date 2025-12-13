/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:24:46 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/12/11 00:26:55 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class   Brain
{
    public:
        Brain();
        Brain(const Brain &other);
        ~Brain();

        Brain &operator=(const Brain &other);

        std::string ideas[100];
};

#endif