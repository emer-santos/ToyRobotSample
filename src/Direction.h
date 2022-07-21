#pragma once

#include <string>

enum class Direction
{
    North = 8,
    East = 6,
    South = 2,
    West = 4
};

Direction convertStrToDirection(const std::string str);
std::string convertDirectionToStr(const Direction face);
