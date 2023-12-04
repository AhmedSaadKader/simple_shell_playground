<<<<<<< HEAD
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
	char *argv[] = {"/bin/ls", "-l", NULL};

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
			execve(argv[0], argv, NULL);
			perror("execve");
			return (1);
		}
		else
		{
			wait(&x);
			i++;
		}
	}
}