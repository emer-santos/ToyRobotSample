#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

// std::string parseInputFile(const std::string filePath)
// {
    
//     std::ifstream inputFile;
//     inputFile.open(filePath);

//     if(inputFile.is_open())
//     {
//         std::string currentLine = "";
//         while(std::getline(inputFile, currentLine))
//         {
//             std::stringstream strstr(currentLine);
//             std::istream_iterator<std:string> ssBegin(strstr);
//             std::istream_iterator<std:string> ssEnd(strstr);
//             std::cout << content << std::endl;
//         }
//         inputFile.close();
//     }
//     else
//     {
//         std::cout << "Cannot find input file" << std::endl;
//         return "";
//     }
//     return content;
// }