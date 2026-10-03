#include <iostream>
#include "lexer.hpp"

int main() {

    std::string input;

    std::cout << "Input: ";
    std::getline(std::cin, input);

    auto tokens = tokenize(input);

    for (const auto& token : tokens) {

        std::cout << "Token: ";

        switch (token.type) {

            case TokenType::Word:
                std::cout << "WORD";
                break;

            case TokenType::Pipe:
                std::cout << "PIPE";
                break;

            case TokenType::RedirectOutput:
                std::cout << "REDIRECT_OUTPUT";
                break;

            case TokenType::RedirectInput:
                std::cout << "REDIRECT_INPUT";
                break;
        }

        std::cout << " -> " << token.value << '\n';
    }
}