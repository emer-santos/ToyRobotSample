#pragma once

#include <memory>
#include <regex>
#include <string>
#include <vector>

#include "Command.h"

std::unique_ptr<BaseCommand> interpretCommandLine(const std::string str)
{
    std::regex delimiters("(,|\\s+)");
    std::sregex_token_iterator first(str.begin(), str.end(), delimiters, -1);
    std::sregex_token_iterator last;
    std::vector<std::string> tokens(first, last);

    if("PLACE" == tokens[0])
    {
        int x = std::stoi(tokens[1]);
        int y = std::stoi(tokens[2]);
        Direction d = convertStrToDirection(tokens[3]);

        return std::make_unique<PlaceCommand>(x, y, d);
    }

    if("MOVE" == tokens[0])
    {
         return std::make_unique<MoveCommand>();
    }

    if("LEFT" == tokens[0])
    {
         return std::make_unique<LeftCommand>();
    }

    if("RIGHT" == tokens[0])
    {
         return std::make_unique<RightCommand>();
    }

    if("REPORT" == tokens[0])
    {
         return std::make_unique<ReportCommand>();
    }

    return std::make_unique<NullCommand>();
}