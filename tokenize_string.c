#include "main.h"

/**
 * tokenize_string - tokenize string and store in array
 *
 * Return: an array containing a tokenized string
*/

char **tokenize_string(char *buffer, char **av)
{
	char *delimiter, *token;
	int i = 0;

	delimiter = " \n";
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		av[i] = strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	av[i] = NULL;

	return (av);
}
