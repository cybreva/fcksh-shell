#include <iostream>
#include <string>

#include "lexer.hpp"
#include "parser.hpp"
#include "executor.hpp"
#include "builtin.hpp"

int main() {

    while (true) {

        std::cout << "fcksh> " << std::flush;

        std::string input;

        if (!std::getline(std::cin, input)) {
            std::cout << '\n';
            break;
        }

        if (input.empty()) {
            continue;
        }

        try {

            auto tokens = tokenize(input);
            auto command = parseCommand(tokens);

            if (command.program == "exit") {
                break;
            }

            if (isBuiltin(command)) {
                executeBuiltin(command);
            }
            else {
                executeCommand(command);
            }

        }
        catch (const std::exception& e) {

            std::cerr << "fcksh: "
                      << e.what()
                      << '\n';
        }
    }

    return 0;
}