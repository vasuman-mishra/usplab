#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
if (argc != 3) {
printf("Usage: %s num1 num2\n", argv[0]);
exit(0);
}
pid_t pid = fork();
if (pid < 0) {
perror("fork failed");
exit(0);
} else if (pid == 0) {
execl("./p23", "p23", argv[1], argv[2], (char *)NULL);
perror("execl failed");
exit(EXIT_FAILURE);
} else {
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status)) {
printf("Child exited with status %d\n", WEXITSTATUS(status));
} else {
printf("Child terminated abnormally\n");
}
}
return 0;
}