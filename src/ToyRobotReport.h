#pragma once

#include "ToyRobotData.h"

class ToyRobotReport
{
public:
    ToyRobotReport();
    ToyRobotReport(const ToyRobotData argData);
    ToyRobotReport(const int posX, const int posY, const Direction face);
    bool isValid() const;
    int getPosX() const;
    int getPosY() const;
    Direction getDirection() const;
    bool operator==(const ToyRobotReport& rhs) const;

private:
    ToyRobotData data;
};