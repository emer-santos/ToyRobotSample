#pragma once

#include <tuple>

#include "commands.h"

class ToyRobot
{
public:
    void place(const int _x, const int _y, const Direction _f)
    {
        x = _x;
        y = _y;
        f = _f;
        isPlacedOnce = true;
    }

    void moveForward()
    {
        y++;
    }

    void rotateLeft()
    {
        switch(f)
        {
            case Direction::North:
                f = Direction::West;
                break;
            case Direction::West:
                f = Direction::South;
                break;
            case Direction::South:
                f = Direction::East;
                break;
            case Direction::East:
                f = Direction::North;
                break;
            default:
                std::cout << "Unknown value" << std::endl;
                break;
        }
    }

    void rotateRight()
    {
        switch(f)
        {
            case Direction::North:
                f = Direction::East;
                break;
            case Direction::West:
                f = Direction::North;
                break;
            case Direction::South:
                f = Direction::West;
                break;
            case Direction::East:
                f = Direction::South;
                break;
            default:
                std::cout << "Unknown value" << std::endl;
                break;
        }
    }

    std::tuple<int, int, Direction> report()
    {
        return std::make_tuple(x, y, f);
    }

private:
    int x = 0;
    int y = 0;
    Direction f = Direction::North;
    bool isPlacedOnce = false;
};