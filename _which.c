#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int ac, char **av)
{
        char *path, *token;
        unsigned int i, n;
        struct stat st;
        char *array[100];
        int counter = 0;
        char filename[100];
		char pathcopy[256];

        if (ac < 2)
            {
                    printf("Usage: %s path_to_file ...\n", av[0]);
                    return (1);
            }
        path = getenv("PATH");
         i = 1;
        while (av[i])
        {
			strcpy(pathcopy, path);
			strcpy(filename, "/");
			strcat(filename, av[i]);
			token = strtok(path, ":\n");
			while(token)
			{
					array[counter] = strdup(token);
					token = strtok(NULL, ":\n");
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
			i++;
			counter = 0;
        }
}