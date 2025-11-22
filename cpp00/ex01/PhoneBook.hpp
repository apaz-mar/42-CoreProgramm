/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:12:14 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/20 15:28:51 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     size;                                       // 0..8
        int     next;                                       // 0..7

    public:
        PhoneBook();

        void    add(const Contact &c);
        int     count() const;                              // returns current size
        const   Contact* at(int idx) const;                 // access by index [0..count()-1]
        static  std::string col10(const std::string &s);    // helper to render a field as width -10 and truncated with '.'
                                                            // static because it doesnt depend on an object to work
};

#endif
