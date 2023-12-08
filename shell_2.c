#include "main.h"

/**
 * main - splits strings
 *
 * Return: Always 0
 */

int main(int ac, char **argv, char **env)
{
	char *av[1024];
	char *buffer = NULL;

	while (ac)
	{
		if (prompt_x(&buffer) == -1)
			return (-1);
		get_command(buffer, av);
		exit_x(av[0]);
		if (file_missing_error(av[0], argv[0]) == -1)
		{
			free_buffer_av(buffer, av);
			continue;
		}
		if (fork_exec(av, env, buffer) == -1)
			return (-1);
	}
	return (0);
}
