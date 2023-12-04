#include <unistd.h>
#include <stdio.h>

/**
 * main - executes a program
 *
 * Return: Always 0
*/

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error: ");
	}
	return (0);
}
