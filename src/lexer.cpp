#include "lexer.hpp"

std::vector<Token> tokenize(const std::string& input) {
    std::vector<Token> tokens;

    std::string current;

    auto flushWord = [&]() {
        if (!current.empty()) {
            tokens.push_back({
                TokenType::Word,
                current
            });

            current.clear();
        }
    };

    for (char ch : input) {

        if (ch == ' ' || ch == '\t') {
            flushWord();
        }
        else if (ch == '|') {
            flushWord();

            tokens.push_back({
                TokenType::Pipe,
                "|"
            });
        }
        else if (ch == '>') {
            flushWord();

            tokens.push_back({
                TokenType::RedirectOutput,
                ">"
            });
        }
        else if (ch == '<') {
            flushWord();

            tokens.push_back({
                TokenType::RedirectInput,
                "<"
            });
        }
        else {
            current += ch;
        }
    }

    flushWord();

    return tokens;
}