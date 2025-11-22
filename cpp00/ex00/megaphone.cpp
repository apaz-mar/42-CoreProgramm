/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:15:02 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/08 21:59:33 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cctype>

// toupper requires their argument to be EOF or representable, chars like ß would be negative and cause undefined behavior.
int main (int ac, char **av)
{
    const char      *p;
    unsigned char   uc;
    int             upper_int;
    char            upper_ch;
    
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; ++i)
    {
        p = av[i];
        while(*p)
        {
            uc = static_cast<unsigned char>(*p);
            upper_int = std::toupper(uc);
            upper_ch = static_cast<char>(upper_int);
            std::cout << upper_ch;
            ++p;
        }
    }
    std::cout << '\n';
    return (0);
}