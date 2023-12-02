#include "main.h"

/**
 * main - splits strings
 *
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	char *str;
	char *delim;
	char *result;

	delim = " ";
	str = malloc(20);
	strcpy(str, argv[1]);
	result = strtok(str, delim);
	while (result != NULL)
	{
		printf("%s\n", result);
		result = strtok(NULL, delim);
	}
	return (0);
}