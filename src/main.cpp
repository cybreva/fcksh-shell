#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include <unistd.h>
#include <sys/wait.h>

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

        if (input == "exit") {
            break;
        }

        // Split input into arguments
        std::istringstream stream(input);

        std::vector<std::string> args;
        std::string token;

        while (stream >> token) {
            args.push_back(token);
        }

        if (args.empty()) {
            continue;
        }

        // execvp() needs char*[]
        std::vector<char*> argv;

        for (auto& arg : args) {
            argv.push_back(arg.data());
        }

        argv.push_back(nullptr);

        pid_t pid = fork();

        if (pid < 0) {
            perror("fcksh: fork");
            continue;
        }

        if (pid == 0) {
            // Child process

            execvp(argv[0], argv.data());

            // execvp() only returns if it failed
            perror("fcksh");
            _exit(127);
        }

        // Parent process

        int status;

        if (waitpid(pid, &status, 0) == -1) {
            perror("fcksh: waitpid");
            continue;
        }
    }

    return 0;
}