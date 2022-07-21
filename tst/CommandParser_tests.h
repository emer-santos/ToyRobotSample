#include "lib/doctest.h"

#include "CommandParser.h"
#include "ToyRobot.h"

TEST_CASE("CommandParser - convertStrToCmd")
{
    ToyRobot robot;
    CommandParser parser;

    std::unique_ptr<BaseCommand> placeCmd = parser.convertStrToCmd("PLACE 2,4,SOUTH");
    CHECK(placeCmd->execute(robot) == true);
    CHECK(robot.report() == ToyRobotReport(2, 4, Direction::South));

    std::unique_ptr<BaseCommand> moveCmd = parser.convertStrToCmd("MOVE");
    CHECK(moveCmd->execute(robot) == true);
    CHECK(robot.report() == ToyRobotReport(2, 3, Direction::South));

    std::unique_ptr<BaseCommand> leftCmd = parser.convertStrToCmd("LEFT");
    CHECK(leftCmd->execute(robot) == true);
    CHECK(robot.report() == ToyRobotReport(2, 3, Direction::East));

    std::unique_ptr<BaseCommand> rightCmd = parser.convertStrToCmd("RIGHT");
    CHECK(rightCmd->execute(robot) == true);
    CHECK(robot.report() == ToyRobotReport(2, 3, Direction::South));
}

TEST_CASE("CommandParser - Not Full Upper Case")
{
    ToyRobot robot;
    CommandParser parser;

    std::unique_ptr<BaseCommand> placeCmd = parser.convertStrToCmd("place 2,4,SouTH");
    CHECK(placeCmd->execute(robot) == true);
    CHECK(robot.report() == ToyRobotReport(2, 4, Direction::South));

    std::unique_ptr<BaseCommand> moveCmd = parser.convertStrToCmd("move");
    CHECK(moveCmd->execute(robot) == true);
    CHECK(robot.report() == ToyRobotReport(2, 3, Direction::South));

    std::unique_ptr<BaseCommand> leftCmd = parser.convertStrToCmd("Left");
    CHECK(leftCmd->execute(robot) == true);
    CHECK(robot.report() == ToyRobotReport(2, 3, Direction::East));

    std::unique_ptr<BaseCommand> rightCmd = parser.convertStrToCmd("RIgHt");
    CHECK(rightCmd->execute(robot) == true);
    CHECK(robot.report() == ToyRobotReport(2, 3, Direction::South));
}

TEST_CASE("CommandParser - Report Command")
{
    CommandParser parser;
    ToyRobot robot;

    std::unique_ptr<BaseCommand> reportCmd = parser.convertStrToCmd("REPORT");
    CHECK(reportCmd->execute(robot) == false);

    robot.place(0,0,Direction::North);
    reportCmd = parser.convertStrToCmd("REPORT");
    CHECK(reportCmd->execute(robot) == true);
}

TEST_CASE("CommandParser - Malformed Place Command")
{
    ToyRobot robot;
    CommandParser parser;

    std::unique_ptr<BaseCommand> placeCmd = parser.convertStrToCmd("place 2, 4, SOUTH");
    CHECK(placeCmd->execute(robot) == false);

    placeCmd = parser.convertStrToCmd("place 2,4abc,SOUTH");
    CHECK(placeCmd->execute(robot) == false);
}