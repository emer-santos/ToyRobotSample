#pragma once

#include "Direction.h"
#include "ToyRobotReport.h"

class ToyRobot
{
public:
    bool place(const int posX, const int posY, const Direction face);
    bool moveForward();
    bool rotateLeft();
    bool rotateRight();
    ToyRobotReport report() const;

private:
    int x = -1;
    int y = -1;
    Direction f = Direction::Unknown;
    bool isOnTable = false;
};