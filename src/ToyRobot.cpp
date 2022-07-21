#include "ToyRobot.h"

#include <iostream>

bool ToyRobot::place(const int posX, const int posY, const Direction face)
{
    if((posY > limits.upperY)||(posY < limits.lowerY)||(posX > limits.upperX)||(posX < limits.lowerX)) 
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
            data.y++;
            if(data.y > limits.upperY)
            {
                data.y = limits.upperY;
                return false;
            }
            break;
        case Direction::East:
            data.x++;
            if(data.x > limits.upperX)
            {
                data.x = limits.upperX;
                return false;
            }
            break;
        case Direction::South:
            data.y--;
            if(data.y < limits.lowerY)
            {
                data.y = limits.lowerY;
                return false;
            }
            break;
        case Direction::West:
            data.x--;
            if(data.x < limits.lowerX)
            {
                data.x = limits.lowerX;
                return false;
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
