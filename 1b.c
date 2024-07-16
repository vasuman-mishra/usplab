#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fd;
    pid_t pid;
    char buffer[100];
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        int b = read(fd, buffer,5);
        if (b < 0) {
            perror("Child failed to read from file");
            exit(EXIT_FAILURE);
        }
        buffer[b] = '\0';
        printf("Child read: %s\n", buffer);
    } else {
        wait(NULL);
        int b = read(fd, buffer,10);
        if (b < 0) {
            perror("Parent failed to read from file");
            exit(EXIT_FAILURE);
        }
        buffer[b] = '\0';
        printf("Parent read: %s\n", buffer);
        close(fd);
    }

    return 0;
}

