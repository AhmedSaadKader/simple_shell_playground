#include <stdio.h>

void print_arg(char **args)
{
	while(*args != NULL)
	{
		printf("%s\n", *args);
		args++;
	}
}

/**
 * main - print args
 * @argc: number of arguments
 * @argv: list of arguments
 *
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	printf("Arguments passed\n");
	print_arg(argv);
	return (0);
}