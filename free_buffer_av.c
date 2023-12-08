#include "main.h"

/**
 * free_buffer_av - frees buffer and av
 * @buffer: getline buffer
 * @av: array of strings
*/

void free_buffer_av(char *buffer, char **av)
{
	int l;

	free(buffer);
	for (l = 0; av[l] != NULL; l++)
		free(av[l]);
}
