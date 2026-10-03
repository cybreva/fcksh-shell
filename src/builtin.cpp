#include "builtin.hpp"

#include <iostream>

#include <unistd.h>
#include <cerrno>
#include <cstring>

bool isBuiltin(const Command& command) {

    return command.program == "cd" ||
           command.program == "exit";
}

int executeBuiltin(const Command& command) {

    if (command.program == "exit") {
        return 0;
    }

    if (command.program == "cd") {

        const char* path;

        if (command.arguments.empty()) {
            path = getenv("HOME");

            if (path == nullptr) {
                std::cerr << "fcksh: HOME is not set\n";
                return 1;
            }
        }
        else {
            path = command.arguments[0].c_str();
        }

        if (chdir(path) == -1) {
            std::cerr << "fcksh: cd: "
                      << std::strerror(errno)
                      << '\n';

            return 1;
        }

        return 0;
    }

    return 1;
}