#pragma once

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
    ToyRobotData data;
    bool isOnTable = false;
};