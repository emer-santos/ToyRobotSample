#include "ToyRobot.h"

#include <iostream>

bool ToyRobot::place(const int posX, const int posY, const Direction face)
{
    if((posY > 4)||(posY < 0)||(posX > 4)||(posX < 0)) 
    {
        return false;
    }

    data.x = posX;
    data.y = posY;
    data.f = face;
    isOnTable = true;

    return true;
}

bool ToyRobot::moveForward()
{
    if(!isOnTable)
    {
        return false;
    }

    switch(data.f)
    {
        case Direction::North:
            if(data.y + 1 > 4)
            {
                return false;
            }
            else
            {
                data.y++;
            }
            break;
        case Direction::East:
            if(data.x + 1 > 4)
            {
                return false;
            }
            else
            {
                data.x++;
            }
            break;
        case Direction::South:
            if(data.y - 1 < 0)
            {
                return false;
            }
            else
            {
                data.y--;
            }
            break;
        case Direction::West:
            if(data.x - 1 < 0)
            {
                return false;
            }
            else
            {
                data.x--;
            }
            break;
        default:
            std::cout << "Unknown value" << std::endl;
            break;
    }

    return true;
}

bool ToyRobot::rotateLeft()
{
    if(!isOnTable)
    {
        return false;
    }

    switch(data.f)
    {
        case Direction::North:
            data.f = Direction::West;
            break;
        case Direction::West:
            data.f = Direction::South;
            break;
        case Direction::South:
            data.f = Direction::East;
            break;
        case Direction::East:
            data.f = Direction::North;
            break;
        default:
            std::cout << "Unknown value" << std::endl;
            break;
    }

    return true;
}

bool ToyRobot::rotateRight()
{
    if(!isOnTable)
    {
        return false;
    }
    
    switch(data.f)
    {
        case Direction::North:
            data.f = Direction::East;
            break;
        case Direction::West:
            data.f = Direction::North;
            break;
        case Direction::South:
            data.f = Direction::West;
            break;
        case Direction::East:
            data.f = Direction::South;
            break;
        default:
            std::cout << "Unknown value" << std::endl;
            break;
    }

    return true;
}

ToyRobotReport ToyRobot::report() const
{
    if(!isOnTable)
    {
        return ToyRobotReport();
    }

    return ToyRobotReport(data);
}
