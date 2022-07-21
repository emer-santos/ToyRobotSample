#include "CommandParser.h"

#include <algorithm>
#include <iostream>
#include <regex>

std::unique_ptr<BaseCommand> CommandParser::convertStrToCmd(const std::string& str)
{
    std::vector<std::string> tokens = tokenize(str, "\\s+");
    // First token should be the command
    transformToUpperCase(tokens[0]);

    if("PLACE" == tokens[0])
    {
        std::vector<std::string> placeTokens = tokenize(tokens[1], ",");

        if(placeTokens.size() != 3)
        {
            std::cout << "Place command arguments have incorrect format." << std::endl;
            return std::make_unique<NullCommand>();
        }

        int x = (isPositiveInt(placeTokens[0])) ? std::stoi(placeTokens[0]) : -1;
        int y = (isPositiveInt(placeTokens[1])) ? std::stoi(placeTokens[1]) : -1;
        transformToUpperCase(placeTokens[2]);
        Direction d = convertStrToDirection(placeTokens[2]);

        if((x < 0)||(y < 0)||(Direction::Unknown == d))
        {
            std::cout << "Place command arguments have incorrect values." << std::endl;
            return std::make_unique<NullCommand>();
        }

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

void CommandParser::transformToUpperCase(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

std::vector<std::string> CommandParser::tokenize(const std::string& str, const std::string& delimiters) const
{
    std::regex delimitersRegEx(delimiters);
    std::sregex_token_iterator first(str.begin(), str.end(), delimitersRegEx, -1);
    std::sregex_token_iterator last;
    return std::vector<std::string>(first, last);
}

bool CommandParser::isPositiveInt(const std::string& str) const
{
    return std::regex_match(str, std::regex("[0-9]+"));
}