#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int file = 0, n;
    char buffer[25];

    if ((file = open("testfile.txt", O_RDONLY)) < 0) {
        perror("file open error");
        return 1;
    }

    if (read(file, buffer, 20) != 20) {
        perror("file read operation failed");
    } else {
        write(STDOUT_FILENO, buffer, 20);
    }
    printf("\n");

    if (lseek(file, 10, SEEK_SET) < 0) {
        perror("lseek operation to beginning of file failed");
    } else {
        if (read(file, buffer, 20) != 20) {
            perror("file read operation failed");
        } else {
            write(STDOUT_FILENO, buffer, 20);
        }
    }
    printf("\n");

    if (lseek(file, 10, SEEK_CUR) < 0) {
        perror("lseek operation from current position failed");
    } else {
        if (read(file, buffer, 20) != 20) {
            perror("file read operation failed");
        } else {
            write(STDOUT_FILENO, buffer, 20);
        }
    }
    printf("\n");

    if ((n = lseek(file, 0, SEEK_END)) < 0) {
        perror("lseek operation to end of file failed");
    } else {
        printf("size of file is %d bytes\n", n);
    }

    close(file);
    return 0;
}

