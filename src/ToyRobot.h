#pragma once

#include <optional>
#include <tuple>

#include "commands.h"

using ToyRobotReport = std::tuple<int, int, Direction>;

class ToyRobot
{
public:
    bool place(const int posX, const int posY, const Direction face)
    {
        if((posY > 4)||(posY < 0)||(posX > 4)||(posX < 0)) 
        {
            return false;
        }

        x = posX;
        y = posY;
        f = face;
        isOnTable = true;

        return true;
    }

    bool moveForward()
    {
        if(!isOnTable)
        {
            return false;
        }

        switch(f)
        {
            case Direction::North:
                if(y + 1 > 4)
                {
                    return false;
                }
                else
                {
                    y++;
                }
                break;
            case Direction::East:
                if(x + 1 > 4)
                {
                    return false;
                }
                else
                {
                    x++;
                }
                break;
            case Direction::South:
                if(y - 1 < 0)
                {
                    return false;
                }
                else
                {
                    y--;
                }
                break;
            case Direction::West:
                if(x - 1 < 0)
                {
                    return false;
                }
                else
                {
                    x--;
                }
                break;
            default:
                std::cout << "Unknown value" << std::endl;
                break;
        }

        return true;
    }

    bool rotateLeft()
    {
        if(!isOnTable)
        {
            return false;
        }

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

        return true;
    }

    bool rotateRight()
    {
        if(!isOnTable)
        {
            return false;
        }
        
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

        return true;
    }

    std::optional<ToyRobotReport> report() const
    {
        if(!isOnTable)
        {
            return std::nullopt;
        }

        return ToyRobotReport(x, y, f);
    }

private:
    int x;
    int y;
    Direction f;
    bool isOnTable = false;
};