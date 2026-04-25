/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:26:10 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/25 19:27:41 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime> // for time in rand()

//according to subject not necessary to design in orthodox canonical form
class Base
{
    public:
        virtual ~Base();
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif