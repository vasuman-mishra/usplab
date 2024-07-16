#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
mode_t new_umask = 0022;
mode_t old_umask;
const char *file_path = "t1.txt";
mode_t new_mode = 0644;
old_umask = umask(new_umask);
printf("Old umask was: %03o, new umask is: %03o\n", old_umask, new_umask);
int fd = open(file_path, O_CREAT | O_WRONLY, 0777);
if (fd == -1) {
perror("open");
return 1;
}
close(fd);
if (chmod(file_path, new_mode) == -1) {
perror("chmod");
return 1;
}
printf("Changed permissions of %s to %03o\n", file_path, new_mode);
return 0;
}