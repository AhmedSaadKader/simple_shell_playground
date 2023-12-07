#include "main.h"

/**
 * tokenize_string - tokenize string and store in array
 *
 * Return: an array containing a tokenized string
*/

char **tokenize_string(char *buffer, char *filename, char **av)
{
	char *delimiter, *token;
	int i = 0;
	struct stat st;

	delimiter = " \n";
	token = strtok(buffer, delimiter);
	if (stat(av[0], &st) == -1)
	{
		printf("%s: No such file or directory\n", filename);
		return (av);
	}
	while (token != NULL)
	{
		av[i] = strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	av[i] = NULL;

	printf("%s", av[0]);

	return (av);
}
