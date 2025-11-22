/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:48 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/20 13:53:50 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact();

        void setFirstName(const std::string &s);
        void setLastName(const std::string &s);
        void setNickName(const std::string &s);
        void setPhoneNumber(const std::string &s);
        void setDarkestSecret(const std::string &s);
        
        const std::string &getFirstName() const;
        const std::string &getLastName() const;
        const std::string &getNickName() const;
        const std::string &getPhoneNumber() const;
        const std::string &getDarkestSecret() const;

        bool isComplete() const;
};

#endif