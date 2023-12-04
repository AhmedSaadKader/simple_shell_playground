#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - creates 5 child processes
 *
 * Return: Always 0
*/

int main()
{
	pid_t my_pid;
	pid_t pid;
	int i = 0, x;
	char *argv[] = {"./split_string", "Ahmed Saad", NULL};

	while (i < 5)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (pid == 0)
		{
			printf("child %d\n", i);
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&x);
			printf("father %d\n", i);
			i++;
		}
	}
}