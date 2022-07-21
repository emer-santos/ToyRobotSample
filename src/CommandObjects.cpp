#include "CommandObjects.h"
#include "ToyRobot.h"

#include <iostream>

bool NullCommand::execute(ToyRobot&) const
{
    std::cout << "Disregarding unknown command" << std::endl;
    return false;
}

PlaceCommand::PlaceCommand(int posX, int posY, Direction face)
:data(posX, posY, face)
{}

bool PlaceCommand::execute(ToyRobot& robot) const
{
    return robot.place(data.x, data.y, data.f);
}

bool MoveCommand::execute(ToyRobot& robot) const
{
    return robot.moveForward();
}

bool LeftCommand::execute(ToyRobot& robot) const
{
    return robot.rotateLeft();
}

bool RightCommand::execute(ToyRobot& robot) const
{
    return robot.rotateRight();
}

bool ReportCommand::execute(ToyRobot& robot) const
{
    const ToyRobotReport result = robot.report();

    if(result.isValid())
    {
        std::cout << result.getPosX() << "," << result.getPosY() << ","<< convertDirectionToStr(result.getDirection()) << std::endl;
        return true;
    }
    return false;
}
