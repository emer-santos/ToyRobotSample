#include <iostream>

#include "GetInputFile.h"
#include "LineInterpreter.h"
#include "Command.h"
#include "ToyRobot.h"

int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return -1;
    }

    const auto contents = getInputFile(argv[1]);

    ToyRobot robot;
    for(auto line : contents)
    {
        auto cmd = interpretCommandLine(line);
        cmd->execute(robot);
    }

    return 0;
}