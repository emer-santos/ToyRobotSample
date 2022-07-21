
#include "lib/doctest.h"

#include "GetInputFile.h"

TEST_CASE("GetInputFile")
{
    std::vector<std::string> file;
    
    SUBCASE("Using input_sample_1")
    {
        file = getInputFile("tst/input_samples/input_sample_1.txt");
        REQUIRE(file.size() == 3);
        CHECK("PLACE 0,0,NORTH" == file[0]);
        CHECK("MOVE" == file[1]);
        CHECK("REPORT" == file[2]);
    }

    SUBCASE("Using input_sample_2")
    {
        file = getInputFile("tst/input_samples/input_sample_2.txt");
        REQUIRE(file.size() == 3);
        CHECK("PLACE 0,0,NORTH" == file[0]);
        CHECK("LEFT" == file[1]);
        CHECK("REPORT" == file[2]);
    }

    SUBCASE("Using input_sample_3")
    {
        file = getInputFile("tst/input_samples/input_sample_3.txt");
        REQUIRE(file.size() == 6);
        CHECK("PLACE 1,2,EAST" == file[0]);
        CHECK("MOVE" == file[1]);
        CHECK("MOVE" == file[2]);
        CHECK("LEFT" == file[3]);
        CHECK("MOVE" == file[4]);
        CHECK("REPORT" == file[5]);
    }
}
