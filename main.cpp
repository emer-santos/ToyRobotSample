#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctest.h"
#include "src/parseInputFile.h"
#include "src/tokenizer.h"

/* TEST_CASE("Input file to string") {
    const std::string actual = parseInputFile("./tst/input_place_move_report.txt");
    CHECK(actual.c_str() == doctest::Contains("PLACE 0,0,NORTH"));
    CHECK(actual.c_str() == doctest::Contains("MOVE"));
    // CHECK(parseInputFile(".\tst\input_place_move_report.txt") == doctest::Contains("REPORT"));
} */

TEST_CASE("Tokenizer - PLACE")
{
    PlaceCommand cmd = tokenizer("PLACE 0,0,NORTH");
    CHECK(0 == cmd.x);
    CHECK(0 == cmd.y);
    CHECK(Direction::North == cmd.direction);

    PlaceCommand cmd = tokenizer("PLACE 1,1,SOUTH");
    CHECK(1 == cmd.x);
    CHECK(1 == cmd.y);
    CHECK(Direction::South == cmd.direction);
}
