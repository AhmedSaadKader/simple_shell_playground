#include <stdio.h>
#include "main.h"

/**
 * main - reads input line
 *
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	char *buffer;
	int char_count;

	buffer = malloc(20);
	write(STDOUT_FILENO, "$ ", 2);
	char_count = read(STDIN_FILENO, buffer, 2);
	write(STDOUT_FILENO, "$ ", 2);
	write(STDOUT_FILENO, buffer, 20);
	free(buffer);
	return (0);
}
