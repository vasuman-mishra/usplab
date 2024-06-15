#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
int main() {
pid_t pid;
int status;
// Get the process ID of the parent process
pid_t parent_pid = getpid();
// Fork a child process
pid = fork();
if (pid == -1) {
// Fork failed
perror("fork");
exit(EXIT_FAILURE);
} else if (pid == 0) {
// Child process
// Get the process ID of the child process
pid_t child_pid = getpid();
printf("Child process (PID: %d) executing...\n", child_pid);
// Execute a program to demonstrate the access function
if (access("example.txt", F_OK) == 0) {
printf("Child process: File exists and can be accessed.\n");
} else {
printf("Child process: File does not exist or cannot be accessed.\n");
}
// Exit the child process
exit(EXIT_SUCCESS);
} else {
// Parent process
// Get the process ID of the parent process
pid_t parent_pid = getpid();
printf("Parent process (PID: %d) executing...\n", parent_pid);
// Wait for the child process to exit
waitpid(pid, &status, 0);
printf("Parent process: Child process (PID: %d) has exited.\n", pid);
}
return 0;
}
