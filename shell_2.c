#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * prompt - displays prompt
 *
 * Return: -1 if end of line
*/

int prompt(char **buffer)
{
	size_t n;
	ssize_t x;

	write(STDOUT_FILENO, "$ ", 2);
		x = getline(buffer, &n, stdin);
		if (x == -1)
		{
			free(buffer);
			*buffer = NULL;
			return (-1);
		}

	return (0);
}

/**
 * main - splits strings
 *
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	char *delim = " \n";
	char *av[64];
	int i = 0, j, l, x;
	char *buffer = NULL;
	pid_t pid;
	struct stat st;

	while (argc)
	{
		x = prompt(&buffer);
		if (x == -1)
		{
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
			if (stat(av[0], &st) == -1)
			{
				printf("%s: No such file or directory\n", argv[0]);
				break;
			}
			while (av[i] != NULL)
			{
				i++;
				av[i] = strtok(NULL, delim);
			}
			av[i] = NULL;
			for (j = 0; j < i; j++)
			{
				av[j] = strdup(av[j]);
			}
			if (execve(av[0], av, NULL) != -1)
			{
				perror("execve:");
			}
			for (l = 0; l < i; l++)
			{
				free(av[l]);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	
	return (0);
}