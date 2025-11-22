/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:38:27 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/20 14:38:29 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact() {}

///-------------------------SETTERS---------------------///

void Contact::setFirstName(const std::string &s)
{
    firstName = s;
}

void Contact::setLastName(const std::string &s)
{
    lastName = s;
}

void Contact::setNickName(const std::string &s)
{
    nickName = s;
}

void Contact::setPhoneNumber(const std::string &s)
{
    phoneNumber = s;
}

void Contact::setDarkestSecret(const std::string &s)
{
    darkestSecret = s;
}

///-------------------------GETTERS--------------------///

const std::string &Contact::getFirstName() const
{
    return (firstName);
}

const std::string &Contact::getLastName() const
{
    return (lastName);
}

const std::string &Contact::getNickName() const
{
    return (nickName);
}

const std::string &Contact::getPhoneNumber() const
{
    return (phoneNumber);
}

const std::string &Contact::getDarkestSecret() const
{
    return (darkestSecret);
}

///--------------------------ALL FIELDS FILLED------------///

bool Contact::isComplete() const
{
    return(!firstName.empty() 
        && !lastName.empty()
        && !nickName.empty()
        && !phoneNumber.empty()
        && !darkestSecret.empty());
}
