/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:35:22 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/25 19:36:03 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Identify.hpp"

Base::~Base()
{}

Base* generate(void)
{
    int r = std::rand() % 3;

    if (r == 0)
        return (new(A));  // new necessary to return a pointer and not lose the result
    else if (r == 1)
        return (new(B));
    else
        return (new(C));
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))   //try to treat this as A
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(...)
    {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(...)
    {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(...)
    {}
}
