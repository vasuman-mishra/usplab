#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void print_file_flags(int fd);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_descriptor>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = atoi(argv[1]);

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    printf("File descriptor: %d\n", fd);
    printf("File flags:\n");

    switch (flags & O_ACCMODE) {
        case O_RDONLY:
            printf("  Read only\n");
            break;
        case O_WRONLY:
            printf("  Write only\n");
            break;
        case O_RDWR:
            printf("  Read/Write\n");
            break;
        default:
            printf("  Unknown access mode\n");
            break;
    }

    if (flags & O_APPEND) printf("  Append\n");
    if (flags & O_NONBLOCK) printf("  Non-blocking\n");
    if (flags & O_SYNC) printf("  Synchronous writes\n");
    if (flags & O_DSYNC) printf("  Synchronous data writes\n");
    if (flags & O_RSYNC) printf("  Synchronous reads\n");
    if (flags & O_CREAT) printf("  Create\n");
    if (flags & O_TRUNC) printf("  Truncate\n");
    if (flags & O_EXCL) printf("  Exclusive\n");
    if (flags & O_NOCTTY) printf("  No terminal control\n");
    if (flags & O_CLOEXEC) printf("  Close-on-exec\n");

    return 0;
}

