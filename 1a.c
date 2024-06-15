#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[]) 
{
    int source, dest, n;
    char buf;
    int filesize;
    int i;

    if (argc != 2) {
        fprintf(stderr, "usage  <source>");
        exit(-1);
    }

    if ((source = open(argv[1], O_RDONLY)) < 0) 
    {   fprintf(stderr, "can't open source\n");
        exit(-1);
    }

    filesize = lseek(source, (off_t) 0, SEEK_END); 
    printf("Source file size is %d\n", filesize);

    for (i = filesize - 1; i >= 0; i--) 
    { 
        lseek(source, (off_t) i, SEEK_SET);

        if ((n = read(source, &buf, 1)) != 1) {
            fprintf(stderr, "can't read 1 byte");
            exit(-1);
        }
	printf("%c",buf);

    }
    close(source);


return 0;
}
