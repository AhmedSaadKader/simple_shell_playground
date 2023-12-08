#include "main.h"

/**
 * prompt - displays prompt
 *
 * Return: -1 if end of line
*/

int prompt_x(char **buffer)
{
	size_t n = 0;
	ssize_t x = 0;

	write(STDOUT_FILENO, "$ ", 2);
		x = getline(buffer, &n, stdin);
		if (x == -1)
		{
			free(*buffer);
			*buffer = NULL;
			return (-1);
		}
	return (0);
}
