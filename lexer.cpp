//
// Created by shaong on 6/11/17.
//

#include <iostream>
#include "lexer.h"

std::vector<std::string> arm::extract(std::string s)
{
    std::vector<std::string> hold;
    std::string delim = " ";
    while((s.find(delim)) != std::string::npos)
    {
        std::string temp = s.substr(0, s.find(delim));

        // [first, last)
        std::remove_if(temp.begin(), temp.end() + 1, [](char c){
            return c == ',' || c == ' ';
        });
        hold.push_back(temp);
        s.erase(0, s.find(delim) + delim.length());
    }
    hold.push_back(s);
    return hold;
}
