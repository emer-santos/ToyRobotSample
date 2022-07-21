#pragma once

#include "Direction.h"

class ToyRobot;

class BaseCommand
{
public:
    virtual bool execute(ToyRobot& robot) const = 0;
};

class NullCommand : public BaseCommand
{
public:
    bool execute(ToyRobot& robot) const override;
};


class PlaceCommand : public BaseCommand
{
public:
    PlaceCommand(int posX, int posY, Direction face);
    bool execute(ToyRobot& robot) const override;

private:
    int x;
    int y;
    Direction f;
};

class MoveCommand : public BaseCommand
{
public:
    bool execute(ToyRobot& robot) const override;
};

class LeftCommand : public BaseCommand
{
public:
    bool execute(ToyRobot& robot) const override;
};

class RightCommand : public BaseCommand
{
public:
    bool execute(ToyRobot& robot) const override;
};

class ReportCommand : public BaseCommand
{
public:
    bool execute(ToyRobot& robot) const override;
};
