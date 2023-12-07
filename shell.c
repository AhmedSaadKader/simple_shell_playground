#include <stdio.h>
#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>


/**
 * main - shell
 *
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t n;
	ssize_t x;
	int count = 0;
	char *delim = "\n";
	char *command[65];
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
		// command = malloc(x * sizeof(char));
		pid = fork();
		if (pid == 0)
		{
			command[count] = strtok(buffer, " \n");
			while (command[count] != NULL)
			{
				count++;
				command[count] = strtok(NULL, " \n");
			}
			command[count] = NULL;
			for (int j = 0; j < count; j++)
			{
				command[j] = strdup(command[j]);
			}
			printf("%s", command[count - 1]);
			if (execve(command[0], command, NULL) != -1)
			{
				perror("execve");
				return (1);
			}
			for (int j = 0; j < count; j++)
			{
				free(command[j]);
			}
		}

		else
		{
			wait(NULL);
		}
	}

	free(buffer);
	return (0);
}
