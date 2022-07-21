#include <iostream>

#include "GetInputFile.h"
#include "CommandObjects.h"
#include "CommandParser.h"
#include "ToyRobot.h"

int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return -1;
    }

    const auto contents = getInputFile(argv[1]);

    CommandParser parser;
    ToyRobot robot;
    for(auto line : contents)
    {
        auto cmd = parser.convertStrToCmd(line);
        cmd->execute(robot);
    }

    return 0;
}