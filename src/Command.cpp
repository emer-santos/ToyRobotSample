#include "Command.h"
#include "ToyRobot.h"

#include <iostream>

bool NullCommand::execute(ToyRobot&) const
{
    std::cout << "Disregarding unknown command" << std::endl;
    return true;
}

PlaceCommand::PlaceCommand(int posX, int posY, Direction face)
:   x(posX),
    y(posY),
    f(face)
{}

bool PlaceCommand::execute(ToyRobot& robot) const
{
    return robot.place(x, y, f);
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
    ToyRobotData result = robot.report();

    if(result.isValid())
    {
        std::cout << result.x << "," << result.y << ","<< convertDirectionToStr(result.f) << std::endl;
        return true;
    }
    return false;
}
