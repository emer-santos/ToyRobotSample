#include "../lib/doctest.h"
#include "../src/LineInterpreter.h"
#include "../src/ToyRobot.h"

#include <memory>

TEST_CASE("Line Interpreter - Command")
{
    std::unique_ptr<BaseCommand> placeCmd = interpretCommandLine("PLACE 2,4,SOUTH");
    ToyRobot robot;

    CHECK(placeCmd->execute(robot) == true);
    CHECK(robot.report().has_value() == true);
    CHECK(robot.report().value() == std::make_tuple(2, 4, Direction::South));

    std::unique_ptr<BaseCommand> moveCmd = interpretCommandLine("MOVE");
    CHECK(moveCmd->execute(robot) == true);
    CHECK(robot.report().has_value() == true);
    CHECK(robot.report().value() == std::make_tuple(2, 3, Direction::South));

    std::unique_ptr<BaseCommand> leftCmd = interpretCommandLine("LEFT");
    CHECK(leftCmd->execute(robot) == true);
    CHECK(robot.report().has_value() == true);
    CHECK(robot.report().value() == std::make_tuple(2, 3, Direction::East));

    std::unique_ptr<BaseCommand> rightCmd = interpretCommandLine("RIGHT");
    CHECK(rightCmd->execute(robot) == true);
    CHECK(robot.report().has_value() == true);
    CHECK(robot.report().value() == std::make_tuple(2, 3, Direction::South));
}

TEST_CASE("Line Interpreter - Report Command")
{
    std::unique_ptr<BaseCommand> reportCmd = interpretCommandLine("REPORT");
    ToyRobot robot;
    CHECK(reportCmd->execute(robot) == false);

    robot.place(0,0,Direction::North);
    reportCmd = interpretCommandLine("REPORT");
    CHECK(reportCmd->execute(robot) == true);
}