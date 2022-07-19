#include "../lib/doctest.h"
#include "../src/ToyRobot.h"

TEST_CASE("Toy Robot - Move")
{
    ToyRobot robot;
    robot.place(3, 3, Direction::North);
    CHECK(robot.report().value() == std::make_tuple(3, 3, Direction::North));

    robot.moveForward();
    CHECK(robot.report().value() == std::make_tuple(3, 4, Direction::North));

    robot.rotateRight();
    robot.moveForward();
    CHECK(robot.report().value() == std::make_tuple(4, 4, Direction::East));

    robot.rotateRight();
    robot.moveForward();
    CHECK(robot.report().value() == std::make_tuple(4, 3, Direction::South));

    robot.rotateRight();
    robot.moveForward();
    CHECK(robot.report().value() == std::make_tuple(3, 3, Direction::West));
}

TEST_CASE("Toy Robot - RotateLeft")
{
    ToyRobot robot;
    robot.place(0, 0, Direction::North);
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::North));

    robot.rotateLeft();
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::West));

    robot.rotateLeft();
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::South));

    robot.rotateLeft();
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::East));

    robot.rotateLeft();
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::North));
}

TEST_CASE("Toy Robot - RotateRight")
{
    ToyRobot robot;
    robot.place(0, 0, Direction::North);
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::North));

    robot.rotateRight();
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::East));

    robot.rotateRight();
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::South));

    robot.rotateRight();
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::West));

    robot.rotateRight();
    CHECK(robot.report().value() == std::make_tuple(0, 0, Direction::North));
}

TEST_CASE("Toy Robot - Bounds Check")
{
    ToyRobot robot;

    robot.place(4, 0, Direction::South);
    CHECK(robot.moveForward() == false);
    CHECK(robot.report().value() == std::make_tuple(4, 0, Direction::South));

    robot.place(0, 4, Direction::West);
    CHECK(robot.moveForward() == false);
    CHECK(robot.report().value() == std::make_tuple(0, 4, Direction::West));

    robot.place(0, 4, Direction::North);
    CHECK(robot.moveForward() == false);
    CHECK(robot.report().value() == std::make_tuple(0, 4, Direction::North));

    robot.place(4, 0, Direction::East);
    CHECK(robot.moveForward() == false);
    CHECK(robot.report().value() == std::make_tuple(4, 0, Direction::East));

    CHECK(robot.place( 0,  5, Direction::North) == false);
    CHECK(robot.place( 0, -1, Direction::North) == false);
    CHECK(robot.place( 5,  0, Direction::North) == false);
    CHECK(robot.place(-1,  0, Direction::North) == false);
}

TEST_CASE("Toy Robot - Disregard Actions Without Place")
{
    ToyRobot robot;

    CHECK(robot.moveForward() == false);
    CHECK(robot.rotateLeft() == false);
    CHECK(robot.rotateRight() == false);
    CHECK(robot.report().has_value() == false);
}