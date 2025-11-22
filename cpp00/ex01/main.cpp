/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:18:25 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/22 15:00:52 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> //for the exit(0)
#include <sstream>  //for ostringstream
#include "PhoneBook.hpp"

// read a non-empty line (subject: saved contact cannot have empty fields, so prompt until is not empty
std::string promptNonEmpty(const std::string &label)
{
    std::string s;
    for(;;)
    {
        std::cout << label;
        if (!std::getline(std::cin, s))
        {
            std::cout << std::endl;
            std::exit(0);
        }
        if (!s.empty())
            return (s);
        std::cout << "Field cannot be emtpy. Try again.\n";
    }
}

void    doAdd(PhoneBook &pb)
{
    Contact c;
    c.setFirstName(promptNonEmpty("First name: "));
    c.setLastName(promptNonEmpty("Last Name: "));
    c.setNickName(promptNonEmpty("Nickname: "));
    c.setPhoneNumber(promptNonEmpty("Phone number: "));
    c.setDarkestSecret(promptNonEmpty("Darkest secret: "));
    if (c.isComplete())
        pb.add(c);
}

//header with max 10 chars and right aligned (padded)
void    printHeader()
{
    std::cout << PhoneBook::col10("index") << "|"
            << PhoneBook::col10("first name") << "|"
            << PhoneBook::col10("last name") << "|"
            << PhoneBook::col10("nickname") << std::endl;
}

void    doSearch(const PhoneBook &pb)
{
    if (pb.count() == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return ;
    }
    printHeader();
    for (int i = 0; i < pb.count(); ++i)
    {
        const Contact *c = pb.at(i);
        
        //writing the index number i into a string (and converting it) with ostringstream
        std::ostringstream  idx;
        idx << i;    //send i into the string-stream
        std::cout << PhoneBook::col10(idx.str()) << "|"
                << PhoneBook::col10(c->getFirstName()) << "|"
                << PhoneBook::col10(c->getLastName()) << "|"
                << PhoneBook::col10(c->getNickName()) << std::endl;
    }
    std::cout << "Index to display: ";
    std::string line;
    if (!std::getline(std::cin, line))
    {
        std::cout << std::endl;
        std::exit(0);
    }

    // validation of empty or non-numeric input
    if (line.empty())
    {
        std::cout << "Invalid index.\n";
        return ;
    }
    for (std::string::size_type k = 0; k < line.size(); ++k)      // loop in the string size. size_type like size_t , unsigned integer
    {
        if (line[k] < '0' || line[k] > '9')
        {
            std::cout << "Invalid index.\n";
            return ;
        }
    }

    // convert the string of digits to an integer
    int idx = 0;
    for (std::string::size_type k = 0; k < line.size(); ++k)
        idx = 10 * idx + (line[k] - '0');

    //get the contact at that index
    const Contact *c = pb.at(idx);
    if (!c)
    {
        std::cout << "Index out of range.\n";
        return ;
    }
    std::cout << "First name: " << c->getFirstName() << std::endl;
    std::cout << "Last name: " << c->getLastName() << std::endl;
    std::cout << "Nickname: " << c->getNickName() << std::endl;
    std::cout << "Phone number: " << c->getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << c->getDarkestSecret() << std::endl;    
}

int main()
{
    PhoneBook   pb;
    std::string cmd;

    //endless loop (exit, return, break necessary)
    for (;;)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd)) //if reading failed (EOF) ...not meaning if reading empty
        {
            std::cout << std::endl;
            break ;
        }
        if (cmd == "ADD")
            doAdd(pb);
        else if (cmd == "SEARCH")
            doSearch(pb);
        else if (cmd == "EXIT")
            break ;
        else if (cmd.empty())
            {}// ignoring any other input as in the subject
        else
            {}// ignore any other controls
    }
    return (0);
}
