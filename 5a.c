#include "apue.h"
#include <fcntl.h>
#include <utime.h>
int main(int argc, char *argv[])
{
int i, fd;
struct stat statbuf;
struct utimbuf timebuf;
for (i = 1; i < argc; i++) {
if (stat(argv[i], &statbuf) < 0) { /* fetch current times */
printf("%s: stat error", argv[i]);
continue;
}
if ((fd = open(argv[i], O_RDWR)) < 0) {
printf ("%s: open error", argv[i]);
continue;
}
close(fd);
timebuf.actime = statbuf.st_atime;
timebuf.modtime = statbuf.st_mtime;
if (utime(argv[i], &timebuf) < 0) 
{ /* reset times */
printf("%s: utime error", argv[i]);
continue;
}
}
exit(0);
}
