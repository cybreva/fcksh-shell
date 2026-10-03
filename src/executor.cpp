#include "executor.hpp"

#include <iostream>
#include <vector>

#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int executeCommand(const Command& command) {

    std::vector<char*> argv;

    argv.push_back(const_cast<char*>(command.program.c_str()));

    for (const auto& arg : command.arguments) {
        argv.push_back(const_cast<char*>(arg.c_str()));
    }

    argv.push_back(nullptr);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fcksh: fork");
        return 1;
    }

    if (pid == 0) {

        // Input redirection
        if (command.redirectInput) {

            int fd = open(
                command.inputFile.c_str(),
                O_RDONLY
            );

            if (fd == -1) {
                perror("fcksh: open");
                _exit(1);
            }

            if (dup2(fd, STDIN_FILENO) == -1) {
                perror("fcksh: dup2");
                close(fd);
                _exit(1);
            }

            close(fd);
        }

        // Output redirection
        if (command.redirectOutput) {

            int fd = open(
                command.outputFile.c_str(),
                O_WRONLY | O_CREAT | O_TRUNC,
                0644
            );

            if (fd == -1) {
                perror("fcksh: open");
                _exit(1);
            }

            if (dup2(fd, STDOUT_FILENO) == -1) {
                perror("fcksh: dup2");
                close(fd);
                _exit(1);
            }

            close(fd);
        }

        execvp(argv[0], argv.data());

        perror("fcksh");
        _exit(127);
    }

    int status;

    if (waitpid(pid, &status, 0) == -1) {
        perror("fcksh: waitpid");
        return 1;
    }

    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }

    return 1;
}