#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - splits strings
 *
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	char *delim = " \n";
	char *av[64];
	int i = 0;
	char *buffer = NULL;
	char *try[] = {"/bin/ls", "-l", NULL};
	size_t n;
	ssize_t x;
	pid_t pid;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		x = getline(&buffer, &n, stdin);
		if (x == -1)
		{
			free(buffer);
			printf("\n");
			return (-1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (pid == 0)
		{
			av[0] = strtok(buffer, delim);
			while (av[i] != NULL)
			{
				i++;
				av[i] = strtok(NULL, delim);
			}
			av[i] = NULL;
			for (int j = 0; j < i; j++)
			{
				av[j] = strdup(av[j]);
			}
			if (execve(av[0], av, NULL) != -1)
			{
				perror("execve:");
			}
			for (int j = 0; j < i; j++)
			{
				free(av[j]);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	
	return (0);
}