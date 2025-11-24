/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:11:42 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/24 17:11:44 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string &input, std::string &s1, std::string &s2)
{
    std::string             result;     //default constructed std::string is an empty string
    std::string::size_type  pos = 0;
    std::string::size_type  found;

    //.find returns the index where the substring begins.
    // npos is a special "not found" value.
    while ((found = input.find(s1, pos)) != std::string::npos)
    {
        result.append(input, pos, found - pos);  // from input at pos, take found-pos characters
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(input, pos, std::string::npos);  //after the loop, copy the rest
    return (result);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>\n";
        return (1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    // Error handling
    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty.\n";
        return (1);
    }
    std::ifstream in(filename.c_str());
    if (!in)
    {
        std::cerr << "Error: cannot open input file.\n";
        return (1);
    }

    // Reading lines
    std::string content;
    std::string line;

    while (std::getline(in, line))
    {
        content = content + line;
        if (!in.eof())
            content = content + "\n";
    }
    in.close();

    // Replace
    std::string output = replaceAll(content, s1, s2);
    // ofstream (open file for writing) only accepts const char*, for that c_str()
    std::ofstream out((filename + ".replace").c_str());
    if (!out)
    {
        std::cerr << "Error: cannot open output file.\n";
        return (1);
    }
    out << output;
    out.close();

    return (0);
}

