#include <iostream>

#include "GetInputFile.h"
#include "CommandObjects.h"
#include "CommandParser.h"
#include "ToyRobot.h"

int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
        std::cout << "Usage: run_app.exe <path\\to\\input\\file>" << std::endl;
        return -1;
    }

    // The file path is on the second argument
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