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

    // For a 5x5 grid:
    // The origin should be at (0,0) 
    // The up-rightmost point should be at (4,4)
    struct CoordinateLimits
    {
        const int lowerX = 0;
        const int upperX = 4;
        const int lowerY = 0;
        const int upperY = 4;
    } limits;
};