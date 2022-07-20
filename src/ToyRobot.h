#pragma once

#include <optional>
#include <tuple>

#include "Command.h"
#include "Direction.h"

using ToyRobotReport = std::tuple<int, int, Direction>;

class ToyRobot
{
public:
    bool place(const int posX, const int posY, const Direction face);
    bool moveForward();
    bool rotateLeft();
    bool rotateRight();
    std::optional<ToyRobotReport> report() const;

private:
    int x;
    int y;
    Direction f;
    bool isOnTable = false;
};