#pragma once

#include "command.hpp"
#include "lexer.hpp"

Command parseCommand(const std::vector<Token>& tokens);