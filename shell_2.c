#include "main.h"

/**
 * main - splits strings
 *
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	char *av[64];
	int i = 0, l, x;
	char *buffer = NULL;
	pid_t pid;

	while (argc)
	{
		x = prompt_x(&buffer);
		if (x == -1)
			return (-1);
		pid = fork();
		if (pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (pid == 0)
		{
			tokenize_string(buffer, argv[0], av);
			if (execve(av[0], av, NULL) != -1)
				perror("execve:");
			for (l = 0; l < i; l++)
				free(av[l]);
		}
		else
			wait(NULL);
	}
	return (0);
}
