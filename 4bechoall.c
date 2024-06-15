// echoall.c
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    printf("Arguments:\n");
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    printf("\nEnvironment Variables:\n");
    for (int i = 0; envp[i] != NULL; ++i) {
        printf("envp[%d]: %s\n", i, envp[i]);
    }

    return 0;
}

