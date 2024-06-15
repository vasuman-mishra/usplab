#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        char *args[] = {"./4binterpreter.sh", "child_arg1", "child_arg2", NULL};
        char *envp[] = {"CHILD_ENV1=value1", "CHILD_ENV2=value2", NULL};
        execve("./4binterpreter.sh", args, envp);
        perror("execve"); // execve only returns on failure
        exit(EXIT_FAILURE);
    } else { // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for the child process to complete

        char *args[] = {"./4binterpreter.sh", "parent_arg1", "parent_arg2", NULL};
        execve("./4binterpreter.sh", args, environ);
        perror("execve"); // execve only returns on failure
        exit(EXIT_FAILURE);
    }

    return 0;
}

