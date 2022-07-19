#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctest.h"
#include "src/parseInputFile.h"
#include "src/tokenizer.h"
#include "src/ToyRobot.h"

/* TEST_CASE("Input file to string") {
    const std::string actual = parseInputFile("./tst/input_place_move_report.txt");
    CHECK(actual.c_str() == doctest::Contains("PLACE 0,0,NORTH"));
    CHECK(actual.c_str() == doctest::Contains("MOVE"));
    // CHECK(parseInputFile(".\tst\input_place_move_report.txt") == doctest::Contains("REPORT"));
} */

TEST_CASE("Tokenizer - PLACE")
{
    {
        PlaceCommand cmd = tokenizer("PLACE 0,0,NORTH");
        CHECK(0 == cmd.x);
        CHECK(0 == cmd.y);
        CHECK(Direction::North == cmd.direction);
    }

    {
        PlaceCommand cmd = tokenizer("PLACE 1,1,SOUTH");
        CHECK(1 == cmd.x);
        CHECK(1 == cmd.y);
        CHECK(Direction::South == cmd.direction);
    }
}

TEST_CASE("Toy Robot - Move")
{
    ToyRobot robot;
    robot.place(0,0,Direction::North);
    CHECK(robot.report() == std::make_tuple(0,0,Direction::North));

    robot.moveForward();
    CHECK(robot.report() == std::make_tuple(0,1,Direction::North));
}

TEST_CASE("Toy Robot - RotateLeft")
{
    ToyRobot robot;
    robot.place(0,0,Direction::North);
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::North));

    robot.rotateLeft();
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::West));

    robot.rotateLeft();
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::South));

    robot.rotateLeft();
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::East));

    robot.rotateLeft();
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::North));
}

TEST_CASE("Toy Robot - RotateRight")
{
    ToyRobot robot;
    robot.place(0,0,Direction::North);
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::North));

    robot.rotateRight();
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::East));

    robot.rotateRight();
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::South));

    robot.rotateRight();
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::West));

    robot.rotateRight();
    CHECK(robot.report() == std::make_tuple(0, 0, Direction::North));
}