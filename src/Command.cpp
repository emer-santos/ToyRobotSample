#include "Commands.h"
#include "ToyRobot.h"

PlaceCommand::PlaceCommand(int posX, int posY, Direction face)
:   x(posX),
    y(posY),
    f(face)
{}

bool PlaceCommand::execute(ToyRobot& robot) const
{
    return robot.place(x, y, f);
}