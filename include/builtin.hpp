#pragma once

#include "command.hpp"

bool isBuiltin(const Command& command);
int executeBuiltin(const Command& command);