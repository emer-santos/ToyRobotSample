#pragma once

#include "Direction.h"

#include <optional>
#include <tuple>

struct ToyRobotData
{
    ToyRobotData()
    :   x(-1),
        y(-1),
        f(Direction::Unknown)
    {}

    ToyRobotData(const int posX, const int posY, const Direction face)
    :   x(posX),
        y(posY),
        f(face)
    {}

    int x;
    int y;
    Direction f;

    bool isValid() const
    {
        return !((x < 0) || (y < 0) || (f == Direction::Unknown));
    }

    bool operator==(const ToyRobotData& rhs) const
    {
        return (std::tie(x, y, f) == std::tie(rhs.x, rhs.y, rhs.f));
    }
};

struct GridData
{
    int x;
    int y;
};

class ToyRobot
{
public:
    bool place(const int posX, const int posY, const Direction face);
    bool moveForward();
    bool rotateLeft();
    bool rotateRight();
    ToyRobotData report() const;

private:
    int x;
    int y;
    Direction f;
    bool isOnTable = false;
};