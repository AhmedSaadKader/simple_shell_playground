#include <stdio.h>
#include "main.h"

/**
 * prompt - displays prompt
 *
 * Return: -1 if end of line
*/

int prompt(char *buffer)
{
	size_t n;
	ssize_t x;

	write(STDOUT_FILENO, "$ ", 2);
		x = getline(&buffer, &n, stdin);
		if (x == -1)
		{
			free(buffer);
			printf("\n");
			return (-1);
		}
	return (0);
}

/**
 * main - reads input line
 *
 * Return: Always 0
*/

int main(void)
{
	char *buffer = NULL;
	while (1)
	{
		prompt(buffer);
	}

	free(buffer);
	return (0);
}
