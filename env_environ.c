#include <stdio.h>


/**
 * main - Entry point
 *
 * @ac: number of inputs
 * @av: aa
 * @env: environment
 *
 * Return: Always 0
*/

int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("%p\n", 	environ);
	printf("%p\n", env);

	return (0);
}
