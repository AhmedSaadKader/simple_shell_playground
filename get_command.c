#include "main.h"

/**
 * get_command - tokenize string and store in array
 * @buffer: getline buffer
 * @av: list of command tokens
 *
 * Return: an array containing a tokenized string
*/

char **get_command(char *buffer, char **av)
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
