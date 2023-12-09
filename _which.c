#include "main.h"

/**
 * _which - gets the path of an argument
 * @av: array of arguments
 *
 * Return: array containing all paths of the argument
*/

char **_which(char *command)
{
	char *path, *token;
	unsigned int n, counter = 0;
	struct stat st;
	char *array[16000];
	char filename[100];
	char pathcopy[256];

	path = getenv("PATH");
	strcpy(pathcopy, path);
	strcpy(filename, "/");
	strcat(filename, command);
	token = strtok(path, ":");
	while(token)
	{
		array[counter] = strdup(token);
		token = strtok(NULL, ":");
		strcat(array[counter], filename);
		counter++;
	}

	for (n = 0; n < counter; n++)
	{
			if (stat(array[n], &st) == 0)
			{
					printf("%s\n", array[n]);
			}
	}
	return (array);
}

int main(int ac, char **av, char **env)
{
    char **paths = _which("ls");

    // Perform operations with the obtained paths if needed

    // Free dynamically allocated memory for paths
    if (paths != NULL) {
        for (int i = 0; paths[i] != NULL; i++) {
            free(paths[i]);
        }
        free(paths);
}
}
