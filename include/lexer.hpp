#pragma once

#include <string>
#include <vector>

enum class TokenType {
    Word,
    Pipe,
    RedirectOutput,
    RedirectInput
};

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(const std::string& input);