#include "parser.hpp"

#include <stdexcept>

Command parseCommand(const std::vector<Token>& tokens) {

    Command command;

    if (tokens.empty()) {
        throw std::runtime_error("empty command");
    }

    std::size_t i = 0;

    // First token must be the program name
    if (tokens[i].type != TokenType::Word) {
        throw std::runtime_error("expected command");
    }

    command.program = tokens[i].value;
    ++i;

    while (i < tokens.size()) {

        const Token& token = tokens[i];

        if (token.type == TokenType::Word) {

            command.arguments.push_back(token.value);
            ++i;
        }

        else if (token.type == TokenType::RedirectInput) {

            ++i;

            if (i >= tokens.size() ||
                tokens[i].type != TokenType::Word) {
                throw std::runtime_error(
                    "expected filename after '<'"
                );
            }

            command.inputFile = tokens[i].value;
            command.redirectInput = true;

            ++i;
        }

        else if (token.type == TokenType::RedirectOutput) {

            ++i;

            if (i >= tokens.size() ||
                tokens[i].type != TokenType::Word) {
                throw std::runtime_error(
                    "expected filename after '>'"
                );
            }

            command.outputFile = tokens[i].value;
            command.redirectOutput = true;

            ++i;
        }

        else if (token.type == TokenType::Pipe) {

            throw std::runtime_error(
                "pipes are not supported by the parser yet"
            );
        }
    }

    return command;
}