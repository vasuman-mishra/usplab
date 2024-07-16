#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return 1;
}
struct stat file_stat;
if (stat(argv[1], &file_stat) == -1) {
perror("stat");
return 1;
}
printf("File: %s\n", argv[1]);
printf("Size: %lld bytes\n", (long long) file_stat.st_size);
printf("Permissions: %o\n", file_stat.st_mode & 0777);
printf("Number of Links: %ld\n", (long) file_stat.st_nlink);
printf("Owner: UID=%ld, GID=%ld\n", (long) file_stat.st_uid, (long) file_stat.st_gid);
printf("Last Access Time: %ld\n", (long) file_stat.st_atime);
return 0;
}