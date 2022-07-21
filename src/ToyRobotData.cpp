#include "ToyRobotData.h"

#include <tuple>

ToyRobotData::ToyRobotData()
:   x(-1),
    y(-1),
    f(Direction::Unknown)
{}

ToyRobotData::ToyRobotData(const int posX, const int posY, const Direction face)
:   x(posX),
    y(posY),
    f(face)
{}

bool ToyRobotData::isValid() const
{
    return !((x < 0) || (y < 0) || (f == Direction::Unknown));
}

bool ToyRobotData::operator==(const ToyRobotData& rhs) const
{
    return (std::tie(x, y, f) == std::tie(rhs.x, rhs.y, rhs.f));
}