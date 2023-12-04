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
	char *program;
	char *command[65];
	// char *av[] = {"/bin/ls", NULL};
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
		program = strtok(buffer, " ");
		while (program != NULL)
		{
			command[count] = program;
			count++;
			program = strtok(NULL, " \n");
		}
		command[count] = NULL;
		pid = fork();
		if (pid == 0)
		{
			printf("%s", command[count - 1]);
			printf("%d\n", count);
			// execve(argv[0], argv, NULL);
			execve(command[0], command, NULL);
			perror("execve");
			return (1);
		}
		else
		{
			wait(&count);
			count = 0;
		}
	}

	free(buffer);
	return (0);
}
