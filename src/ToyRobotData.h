#pragma once

#include "Direction.h"

struct ToyRobotData
{
    ToyRobotData();
    ToyRobotData(const int posX, const int posY, const Direction face);
    bool isValid() const;
    bool operator==(const ToyRobotData& rhs) const;

    int x;
    int y;
    Direction f;
};