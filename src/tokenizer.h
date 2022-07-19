#pragma once

#include <string>
#include <map>
#include <vector>
#include <regex>

#include "commands.h"

Direction convertStrToDirection(const std::string str)
{
    std::map<std::string, Direction> stringDirection = {
            {"NORTH", Direction::North},
            {"SOUTH", Direction::South},
            {"EAST", Direction::East},
            {"WEST", Direction::West}
        };

    auto it = stringDirection.find(str);
    if(it != stringDirection.end())
    {
        return it->second;
    }
    else 
    {
        return Direction::North;
    }
}

PlaceCommand tokenizer(const std::string str)
{
    std::regex delimiters("(,|\\s+)");
    std::sregex_token_iterator first(str.begin(), str.end(), delimiters, -1);
    std::sregex_token_iterator last;
    std::vector<std::string> tokens(first, last);

    // for(auto s : tokens)
    //     std::cout << s << std::endl;

    int x = std::stoi(tokens[1]);
    int y = std::stoi(tokens[2]);
    Direction d = convertStrToDirection(tokens[3]);

    return PlaceCommand(x, y, d);
}