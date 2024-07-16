#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
return 1;
}
int src_fd = open(argv[1], O_RDONLY);
if (src_fd == -1) {
perror("open source");
return 1;
}
int dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
if (dst_fd == -1) {
perror("open destination");
return 1;
}
char buffer[BUFFER_SIZE];
ssize_t bytes_read;
while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
if (write(dst_fd, buffer, bytes_read) != bytes_read) {
perror("write");
return 1;
}
}
if (bytes_read == -1) {
perror("read");
}
close(src_fd);
close(dst_fd);
return 0;
}