#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char *command = NULL;
    size_t bufsize = 0;
    char *token;
    char *delim = " \n";
    char *array[100];
    int counter = 0;
    while(1)
	{
        printf("$ ");
        fflush(stdout); // Ensure the prompt is displayed
        if (getline(&command, &bufsize, stdin) != -1)
        {
            printf("Command entered: %s", command);
            token = strtok(command, delim);
            while (token != NULL)
            {
            	array[counter] = strdup(token);
                printf("%s\n", array[counter]);
                counter++;
                token = strtok(NULL, delim);
            }
            array[counter] = NULL;
        }
        execve(array[0], array, NULL);
	}
	free(command);
    return (0);
}
