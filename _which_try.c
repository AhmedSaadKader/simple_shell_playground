#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av) {
    if (ac < 2) {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return 1;
    }

    char *path = getenv("PATH");
    char *token;
    unsigned int counter = 0;
    struct stat st;
    char *array[100];

    if (path == NULL) {
        printf("PATH environment variable is not set.\n");
        return 1;
    }

    token = strtok(path, ":");

    while (token != NULL && counter < 100) {
        array[counter] = strdup(token);
        if (array[counter] == NULL) {
            perror("strdup");
            return 1;
        }
        token = strtok(NULL, ":");
        counter++;
    }

    for (int i = 1; i < ac; i++) {
        char filename[100];
        strcpy(filename, "/");
        strcat(filename, av[i]);

        for (unsigned int n = 0; n < counter; n++) {
            char pathcopy[256];
            strcpy(pathcopy, array[n]); // Copy the path into pathcopy

            char path_filename[256];
            snprintf(path_filename, sizeof(path_filename), "%s%s", pathcopy, filename);

            if (stat(path_filename, &st) == 0) {
                printf("%s\n", path_filename);
            }
            free(array[n]); // Free allocated memory for the directory path
            array[n] = NULL;
        }
    }

    return 0;
}
