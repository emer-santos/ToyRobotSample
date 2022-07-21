#include "Direction.h"

#include <map>

Direction convertStrToDirection(const std::string& str)
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
        return Direction::Unknown;
    }
}

std::string convertDirectionToStr(const Direction face)
{
    switch(face)
    {
        case Direction::North:
            return "NORTH";
            break;
        case Direction::South:
            return "SOUTH";
            break;
        case Direction::East:
            return "EAST";
            break;
        case Direction::West:
            return "WEST";
            break;
        default:
            return "Unknown";
            break;
    }
}