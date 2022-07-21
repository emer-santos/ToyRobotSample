#pragma once

#include "Direction.h"

class ToyRobotReport
{
public:
    ToyRobotReport();
    ToyRobotReport(const int posX, const int posY, const Direction face);
    bool isValid() const;
    int getPosX() const;
    int getPosY() const;
    Direction getDirection() const;
    bool operator==(const ToyRobotReport& rhs) const;

private:
    int x;
    int y;
    Direction f;
};