#include <stdio.h>
#include "main.h"

/**
 * main - reads input line
 *
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t n;
	ssize_t x;

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
		write(STDOUT_FILENO, "$ ", 2);
		printf("%s", buffer);
	}

	free(buffer);
	return (0);
}
