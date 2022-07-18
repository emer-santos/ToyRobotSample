#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctest.h"
#include "src/parseInputFile.h"

TEST_CASE("Input file to string") {
    const std::string actual = parseInputFile("./tst/input_place_move_report.txt");
    CHECK(actual.c_str() == doctest::Contains("PLACE 0,0,NORTH"));
    CHECK(actual.c_str() == doctest::Contains("MOVE"));
    // CHECK(parseInputFile(".\tst\input_place_move_report.txt") == doctest::Contains("REPORT"));
}