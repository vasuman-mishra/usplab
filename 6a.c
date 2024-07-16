#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {
int fd1, fd2;char buf[50];
fd1 = open("example.txt", O_RDWR, 0);
fd2 = open("sample.txt", O_CREAT | O_RDWR, 0777);
// Duplicate fd1 to fd2 using dup2
fd2 = dup2(fd1, fd2);
if (fd2 < 0) {
printf("dup2 error\n");
close(fd1);
return 1;
}
printf("File descriptors: %d %d \n", fd1, fd2);
if (read(fd1, buf, 20) < 0) {
	printf("read error\n");
	close(fd1);
	close(fd2);
	return 1;
}
if (lseek(fd2, 0, SEEK_END) < 0) {
	printf("lseek error\n");
	close(fd1);
	close(fd2);
	return 1;
}
if (write(fd2, buf, 20) < 0) {
printf("write error\n");
close(fd1);
close(fd2);
return 1;
}
printf("%s\n", buf);
close(fd1);
close(fd2);
return 0;
}