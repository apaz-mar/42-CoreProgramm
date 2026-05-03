/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 11:46:37 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/05/03 13:53:35 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>        // std::stack is a container adapter, not a real container like vector or list; it wrapps on top of another container
{
    public:
        MutantStack() : std::stack<T>() {}          //templates must be fully defined in the header
        ~MutantStack() {}
        MutantStack(const MutantStack& other) :std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other)
        {
            std::stack<T>::operator=(other);
            return (*this);
        }
    
        typedef typename std::stack<T>::container_type::iterator iterator;          //container_type is a typedef inside std::stack.... iterator of whatever container type  stack is using internally

        iterator begin()
        {
            return (this->c.begin());              //c is the protected underlying container inside std::stack..... stack<T> internally has a protected container_type c
        }
        iterator end()
        {
            return (this->c.end());
        }
};

#endif