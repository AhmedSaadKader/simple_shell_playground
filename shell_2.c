#include "main.h"

/**
 * main - splits strings
 *
 * Return: Always 0
 */

int main(int ac, char **argv, char **env)
{
	char **av;
	int i, l, x;
	char *buffer = NULL;
	pid_t pid;
	struct stat st;
	{
		/* data */
	};

	while (ac)
	{
		x = prompt_x(&buffer);
		if (x == -1)
			return (-1);
		i = strlen(buffer) + 1;
		av = malloc(sizeof(char) * (strlen(buffer) + 1));
		tokenize_string(buffer, av);
		if (strcmp(av[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		if (stat(av[0], &st) == -1)
		{
			printf("%s: No such file or directory\n", argv[0]);
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (pid == 0)
		{
			if (execve(av[0], av, env) != -1)
				perror("execve:");
			for (l = 0; l < i; l++)
				free(av[l]);
			free(av);
			free(buffer);
		}
		else
			wait(NULL);
	}
	return (0);
}
