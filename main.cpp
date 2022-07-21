#include <iostream>

#include "src/parseInputFile.h"
#include "src/LineInterpreter.h"
#include "src/Command.h"
#include "src/ToyRobot.h"

int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return -1;
    }

    // for(int i = 0; i < argc; i++)
    //     std::cout << argv[i] << std::endl;

    const auto contents = getInputFile(argv[1]);

    ToyRobot robot;
    for(auto line : contents)
    {
        auto cmd = interpretCommandLine(line);
        cmd->execute(robot);
    }

    return 0;
}