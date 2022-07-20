#pragma once

#include "Direction.h"

class ToyRobot;

class PlaceCommand
{
public:
    PlaceCommand(int posX, int posY, Direction face);
    bool execute(ToyRobot& robot) const;

private:
    int x;
    int y;
    Direction f;
};