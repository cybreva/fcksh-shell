#pragma once

#include <string>
#include <vector>

struct Command {
    std::string program;
    std::vector<std::string> arguments;

    std::string inputFile;
    std::string outputFile;

    bool redirectInput = false;
    bool redirectOutput = false;
};