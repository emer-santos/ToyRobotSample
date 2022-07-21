#pragma once

#include "CommandObjects.h"

#include <memory>
#include <string>
#include <vector>

class CommandParser
{
public:
    std::unique_ptr<BaseCommand> convertStrToCmd(const std::string& str);

private:
    void transformToUpperCase(std::string& str);
    std::vector<std::string> tokenize(const std::string& str, const std::string& delimiters) const;
    bool isPositiveInt(const std::string& str) const;
};
