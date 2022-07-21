#include "ToyRobotReport.h"

#include <tuple>

ToyRobotReport::ToyRobotReport()
:   x(-1),
    y(-1),
    f(Direction::Unknown)
{}

ToyRobotReport::ToyRobotReport(const int posX, const int posY, const Direction face)
:   x(posX),
    y(posY),
    f(face)
{}

bool ToyRobotReport::isValid() const
{
    return !((x < 0) || (y < 0) || (f == Direction::Unknown));
}

int ToyRobotReport::getPosX() const
{
    return x;
}

int ToyRobotReport::getPosY() const
{
    return y;
}

Direction ToyRobotReport::getDirection() const
{
    return f;
}

bool ToyRobotReport::operator==(const ToyRobotReport& rhs) const
{
    return (std::tie(x, y, f) == std::tie(rhs.x, rhs.y, rhs.f));
}