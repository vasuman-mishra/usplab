#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *original_file = argv[1];
    char hard_link[256];
    char soft_link[256];
    struct stat fileStat;

    snprintf(hard_link, sizeof(hard_link), "%s_hardlink", original_file);
    snprintf(soft_link, sizeof(soft_link), "%s_softlink", original_file);

    // Create a file to link to
    int fd = open(original_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd, "Hello, World!\n", 14);
    close(fd);

    // Create a hard link
    if (link(original_file, hard_link) < 0) {
        perror("link");
        exit(EXIT_FAILURE);
    }

    // Create a soft link
    if (symlink(original_file, soft_link) < 0) {
        perror("symlink");
        exit(EXIT_FAILURE);
    }

    // Print information about the original file
    printf("Original file info:\n");
    if (stat(original_file, &fileStat) == 0) {
        printf("Inode: %ld\n", (long)fileStat.st_ino);
        printf("Hard link count: %ld\n", (long)fileStat.st_nlink);
        printf("Size: %ld bytes\n", (long)fileStat.st_size);
        printf("Permissions: %o\n", fileStat.st_mode & 0777);
        printf("Last access: %s", ctime(&fileStat.st_atime));
        printf("Last modification: %s", ctime(&fileStat.st_mtime));
        printf("Last status change: %s\n", ctime(&fileStat.st_ctime));
    } else {
        perror("stat");
    }
    
    // Print information about the hard link
    printf("Hard link info:\n");
    if (stat(hard_link, &fileStat) == 0) {
        printf("Inode: %ld\n", (long)fileStat.st_ino);
        printf("Hard link count: %ld\n", (long)fileStat.st_nlink);
        printf("Size: %ld bytes\n", (long)fileStat.st_size);
        printf("Permissions: %o\n", fileStat.st_mode & 0777);
        printf("Last access: %s", ctime(&fileStat.st_atime));
        printf("Last modification: %s", ctime(&fileStat.st_mtime));
        printf("Last status change: %s\n", ctime(&fileStat.st_ctime));
    } else {
        perror("stat");
    }

    // Print information about the soft link
    printf("Soft link info:\n");
    if (lstat(soft_link, &fileStat) == 0) {
        printf("Inode: %ld\n", (long)fileStat.st_ino);
        printf("Hard link count: %ld\n", (long)fileStat.st_nlink);
        printf("Size: %ld bytes\n", (long)fileStat.st_size);
        printf("Permissions: %o\n", fileStat.st_mode & 0777);
        printf("Last access: %s", ctime(&fileStat.st_atime));
        printf("Last modification: %s", ctime(&fileStat.st_mtime));
        printf("Last status change: %s\n", ctime(&fileStat.st_ctime));
    } else {
        perror("lstat");
    }

    // Cleanup
    if (unlink(original_file) < 0) {
        perror("unlink original");
    }
    if (unlink(hard_link) < 0) {
        perror("unlink hard link");
    }
    if (unlink(soft_link) < 0) {
        perror("unlink soft link");
    }

    return 0;
}

