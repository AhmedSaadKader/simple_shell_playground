#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * main - Prints the environment variable
 * @ac: number of arguments
 * @av: array of arguments
 * @env: array of strings of environment variable
 *
 * Return: Always 0
*/

int main(int ac, char **av, char **env)
{
	int i = 0;
	char *env_var;
	char *token;

	if (ac < 2)
	{
		printf("Usage: %s environment variable\n", av[0]);
		return (1);
	}

	env_var = av[1];
	while (env[i])
	{
		token = strtok(env[i], "=");
		if (strcmp(token, env_var) == 0)
		{
			token = strtok(NULL, "\0");
			printf("%s\n", token);
			return (0);
		}
		i++;
	}
	printf("not found\n");
	return (0);
}
