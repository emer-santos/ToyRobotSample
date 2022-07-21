#include "ToyRobotReport.h"


ToyRobotReport::ToyRobotReport()
:data()
{}

ToyRobotReport::ToyRobotReport(const ToyRobotData argData)
:data(argData)
{}

ToyRobotReport::ToyRobotReport(const int posX, const int posY, const Direction face)
:data(posX, posY, face)
{}

bool ToyRobotReport::isValid() const
{
    return data.isValid();
}

int ToyRobotReport::getPosX() const
{
    return data.x;
}

int ToyRobotReport::getPosY() const
{
    return data.y;
}

Direction ToyRobotReport::getDirection() const
{
    return data.f;
}

bool ToyRobotReport::operator==(const ToyRobotReport& rhs) const
{
    return data == rhs.data;
}