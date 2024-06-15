#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 4096

void report_error(const char *message, const char *filename) {
    fprintf(stderr, "%s: %s - %s\n", message, filename, strerror(errno));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_file = argv[1];
    const char *destination_file = argv[2];
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // Open the source file
    src_fd = open(source_file, O_RDONLY);
    if (src_fd == -1) {
        report_error("Error opening source file", source_file);
        exit(EXIT_FAILURE);
    }

    // Open/Create the destination file
    dest_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        report_error("Error opening/creating destination file", destination_file);
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    // Copy the contents from source to destination
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            report_error("Error writing to destination file", destination_file);
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        report_error("Error reading from source file", source_file);
    }

    // Close the files
    if (close(src_fd) == -1) {
        report_error("Error closing source file", source_file);
    }

    if (close(dest_fd) == -1) {
        report_error("Error closing destination file", destination_file);
    }

    return EXIT_SUCCESS;
}

