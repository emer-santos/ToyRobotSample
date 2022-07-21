#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctest.h"

#include "tst/LineInterpreter_tests.h"
#include "tst/ToyRobot_tests.h"

#include "src/parseInputFile.h"

TEST_CASE("File Reader")
{
    std::vector<std::string> file = getInputFile("tst/input_place_move_report.txt");
    REQUIRE(file.size() > 0);
    CHECK("PLACE 0,0,NORTH" == file[0]);
    CHECK(file[1] == "MOVE");
    CHECK(file[2] == "REPORT");
}

