#pragma once

#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> getInputFile(const std::string filePath)
{
    std::vector<std::string> contents;
    std::ifstream inputFile;
    inputFile.open(filePath);

    if(inputFile.is_open())
    {
        std::string currentLine = "";
        while(std::getline(inputFile, currentLine))
        {
            contents.push_back(currentLine);
        }
        inputFile.close();
    }
    else
    {
        std::cout << "Cannot find input file" << std::endl;
    }
    return contents;
}