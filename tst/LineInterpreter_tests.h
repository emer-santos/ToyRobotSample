#include "lib/doctest.h"

#include "LineInterpreter.h"
#include "ToyRobot.h"

TEST_CASE("Line Interpreter - Command")
{
    std::unique_ptr<BaseCommand> placeCmd = interpretCommandLine("PLACE 2,4,SOUTH");
    ToyRobot robot;

    CHECK(placeCmd->execute(robot) == true);

    auto report = robot.report();
    CHECK(robot.report() == ToyRobotReport(2, 4, Direction::South));

    std::unique_ptr<BaseCommand> moveCmd = interpretCommandLine("MOVE");
    CHECK(moveCmd->execute(robot) == true);
    
    report = robot.report();
    CHECK(robot.report() == ToyRobotReport(2, 3, Direction::South));

    std::unique_ptr<BaseCommand> leftCmd = interpretCommandLine("LEFT");
    CHECK(leftCmd->execute(robot) == true);
    report = robot.report();
    CHECK(robot.report() == ToyRobotReport(2, 3, Direction::East));

    std::unique_ptr<BaseCommand> rightCmd = interpretCommandLine("RIGHT");
    CHECK(rightCmd->execute(robot) == true);
    report = robot.report();
    CHECK(robot.report() == ToyRobotReport(2, 3, Direction::South));
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